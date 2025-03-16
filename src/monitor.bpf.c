#include <vmlinux.h>
#include <bpf/bpf_helpers.h>

struct proc_cpu_stats {
    __u32 pid;
    __u64 total_cpu_time;
    __u64 last_update;
    __u32 cpu;
};

struct switch_args {
    __u16 common_type;
    __u8 common_flags;
    __u8 common_preempt_count;
    __u32 common_pid;
    char prev_comm[16];
    __u32 prev_pid;
    __u32 prev_prio;
    __s64 prev_state;
    char next_comm[16];
    __u32 next_pid;
    __u32 next_prio;
};

struct exit_args {
    __u16 common_type;
    __u8 common_flags;
    __u8 common_preempt_count;
    __u32 common_pid;
    char comm[16];
    __u32 pid;
    int prio;
};

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 204800);
    __type(key, __u32);
    __type(value, __u64);
} start_time SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 204800);
    __type(key, __u32);
    __type(value, struct proc_cpu_stats);
} cpu_stats SEC(".maps");

// 跟踪进程切换事件，所有的时间计数都是增量计数，这样可以避免数据清除带来
SEC("tracepoint/sched/sched_switch")
int trace_sched_switch(struct switch_args *ctx)
{
    __u64 ts = bpf_ktime_get_ns();
    __u32 prev_pid = ctx->prev_pid;
    __u32 next_pid = ctx->next_pid;
    __u32 cpu = bpf_get_smp_processor_id();

    //进程切入的时候，取前一个进程的开始时间，然后计算持续的多长时间，这代表了当前进程使用了多长时间的CPU
    __u64 *prev_ts = bpf_map_lookup_elem(&start_time, &prev_pid);
    if (prev_ts) {
        __u64 delta = ts - *prev_ts;
        struct proc_cpu_stats *stats = bpf_map_lookup_elem(&cpu_stats, &prev_pid);
        //更新缓存的cpu_stats，这代表着累加的是CPU的时间
        if (stats) {
            // 更新统计信息
            stats->total_cpu_time += delta;
            stats->last_update = ts;
            stats->cpu = cpu;
        } else {
            // 如果第一次记录这个进程，没那么先进行初始化，创建新的统计记录
            struct proc_cpu_stats new_stats = {
                .pid = prev_pid,
                .total_cpu_time = delta,
                .last_update = ts,
                .cpu = cpu
            };
            bpf_map_update_elem(&cpu_stats, &prev_pid, &new_stats, BPF_ANY);
        }
    }

    // 记录新进程的开始时间，和前面的分支差不多，记录开始时间，后面再次进行切换的时候会更新当前的进程的CPU时间
    bpf_map_update_elem(&start_time, &next_pid, &ts, BPF_ANY);

    return 0;
}

// 定期采样更新
SEC("perf_event")
int sample_cpu_stats(struct bpf_perf_event_data *ctx)
{
    __u64 ts = bpf_ktime_get_ns();
    __u32 pid = bpf_get_current_pid_tgid() >> 32;
    __u32 cpu = bpf_get_smp_processor_id();

    // 更新当前运行进程的统计信息
    __u64 *start_ts = bpf_map_lookup_elem(&start_time, &pid);
    if (start_ts) {
        __u64 delta = ts - *start_ts;
        struct proc_cpu_stats *stats = bpf_map_lookup_elem(&cpu_stats, &pid);
        if (stats) {
            stats->total_cpu_time += delta;
            stats->last_update = ts;
            stats->cpu = cpu;
            *start_ts = ts;  // 更新开始时间
        }
    }

    return 0;
}

// 只有进程退出的时候才去做清空操作，可以尽量的保证采样的准确性
SEC("tracepoint/sched/sched_process_exit")
int trace_sched_process_exit(struct switch_args *ctx)
{
    __u32 pid = ctx->prev_pid;

    // 只在进程真正退出时清理数据
    bpf_map_delete_elem(&start_time, &pid);
    bpf_map_delete_elem(&cpu_stats, &pid);

    return 0;
}

char LICENSE[] SEC("license") = "GPL";
