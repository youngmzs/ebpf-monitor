#ifndef MONITOR_H
#define MONITOR_H

#include <stdint.h>

struct proc_cpu_stats {
    uint32_t pid;
    uint64_t total_cpu_time;  // 总CPU时间（纳秒）
    uint64_t last_update;     // 最后更新时间
    uint32_t cpu;            // CPU核心ID
};

#endif /* MONITOR_H */