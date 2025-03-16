#ifndef CGROUP_CONFIG_H
#define CGROUP_CONFIG_H

#include <stdbool.h>

#define MAX_CGROUP_PATH 512
#define MAX_TARGET_CGROUPS 16

// 目标 cgroup 配置
struct target_cgroup {
    char path[MAX_CGROUP_PATH];    // cgroup 完整路径
    double current_quota;          // 当前 CPU 配额
    double total_usage;           // 当前总 CPU 使用率
    int process_count;            // 当前进程数量
    int high_count;               // 高使用率计数
    int low_count;                // 低使用率计数
};

// 全局配置结构
struct cgroup_monitor_config {
    struct target_cgroup cgroups[MAX_TARGET_CGROUPS];
    int cgroup_count;
};

// 初始化配置
void init_cgroup_config(struct cgroup_monitor_config *config);

// 添加目标 cgroup
int add_target_cgroup(struct cgroup_monitor_config *config, const char *cgroup_path);

void update_cgroup_stats(struct target_cgroup *cgroup, double cpu_usage);

// 检查是否是目标 cgroup
bool is_target_cgroup(struct cgroup_monitor_config *config, const char *cgroup_path);

// 获取 cgroup 配置
struct target_cgroup *get_target_cgroup(struct cgroup_monitor_config *config, 
                                      const char *cgroup_path);

#endif /* CGROUP_CONFIG_H */