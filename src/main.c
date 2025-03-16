#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <bpf/libbpf.h>
#include <monitor.skel.h>
#include <monitor.h>
#include <cpu_calculator.h>
#include <cgroup_config.h>

#define MAX_PROCESSES 10240
static volatile bool running = true;

struct process_info {
    struct cpu_usage_context cpu_ctx;
    int pid;
    char cgroup_path[MAX_CGROUP_PATH];
    bool active;
};

static struct process_info process_table[MAX_PROCESSES];

static void sig_handler(int sig)
{
    running = false;
}

int main(int argc, char **argv)
{
    struct monitor_bpf *skel;
    int err;
    // 获取系统CPU核心数,用于后续计算使用率
    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    // 设置信号处理
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);
    // 打开和加载BPF程序
    skel = monitor_bpf__open_and_load();
    if (!skel) {
        fprintf(stderr, "Failed to open BPF program\n");
        return 1;
    }
    // 附加BPF程序
    err = monitor_bpf__attach(skel);
    if (err) {
        fprintf(stderr, "Failed to attach BPF program: %d\n", err);
        goto cleanup;
    }
    // 初始化 cgroup 配置
    struct cgroup_monitor_config cgroup_config;
    init_cgroup_config(&cgroup_config);
    // 添加要监控的目标 cgroup，避免修改不应该修改的cgroup
    add_target_cgroup(&cgroup_config, "/sys/fs/cgroup/user.slice/user-1000.slice/user@1000.service/app.slice/app-gnome-clion-4647.scope");
    //获取eBPF数据的采样
    struct bpf_map *map = skel->maps.cpu_stats;
    // 主循环
    while (running)
    {
        // 清零所有 cgroup 的统计数据
        for (int i = 0; i < cgroup_config.cgroup_count; i++) {
            cgroup_config.cgroups[i].total_usage = 0;
            cgroup_config.cgroups[i].process_count = 0;
        }
        // 遍历BPF map获取CPU使用数据
        __u32 cur_key = 0, next_key = 0;
        bool first = true;
        while (!bpf_map__get_next_key(map, first ? NULL : &cur_key, &next_key,sizeof(__u32)))
        {
            first = false;
            struct proc_cpu_stats cpu_stats;
            if (!bpf_map__lookup_elem(map, &next_key,sizeof(__u32),&cpu_stats,sizeof(struct proc_cpu_stats),0))
            {
                //记录一下进程的情况
                int idx = next_key % MAX_PROCESSES;
                struct process_info *info = &process_table[idx];
                // 如果是新进程，初始化上下文
                if (!info->active) {
                    init_cpu_usage_context(&info->cpu_ctx);
                    info->pid = cpu_stats.pid;
                    info->active = true;
                    // 获取进程的 cgroup 路径，用于获取cgroup信息
                    FILE *f;
                    char cmd[256];
                    char buf[MAX_CGROUP_PATH];
                    snprintf(cmd, sizeof(cmd),
                            "cat /proc/%d/cgroup | cut -d: -f3",
                            info->pid);
                    f = popen(cmd, "r");
                    if (f) {
                        if (fgets(buf, sizeof(buf), f) != NULL) {
                            // 移除末尾的换行符
                            buf[strcspn(buf, "\n")] = 0;
                            //拼接前缀 "/sys/fs/cgroup" 和 buf 内容
                            snprintf(info->cgroup_path, MAX_CGROUP_PATH, "/sys/fs/cgroup%s", buf);
                        }
                        pclose(f);
                    }
                }
                // 计算CPU使用率
                struct cpu_usage_result usage = calculate_cpu_usage(
                    &info->cpu_ctx,
                    cpu_stats.total_cpu_time,
                    cpu_stats.last_update,
                    num_cpus
                );
                // 查找进程所属的目标 cgroup，避免误更新其他的cgroup
                struct target_cgroup *cgroup = get_target_cgroup(&cgroup_config, info->cgroup_path);
                //printf("====================cgroup is: %s\n", info->cgroup_path);
                if (cgroup != NULL) {
                    update_cgroup_stats(cgroup,usage.current_usage);
                    //printf("====================Process %d in cgroup %s: CPU usage %.2f%%\n",info->pid, info->cgroup_path, usage.current_usage);
                }
                printf("pid is %-6u and useage is %f (Core %u)\n", cpu_stats.pid,usage.current_usage,cpu_stats.cpu);
            }
            cur_key = next_key;  // 更新当前键
        }
        //每秒采样一次
        sleep(1);
    }

cleanup:
    monitor_bpf__destroy(skel);
    return err != 0;
}
