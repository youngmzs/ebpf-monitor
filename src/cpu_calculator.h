#ifndef CPU_CALCULATOR_H
#define CPU_CALCULATOR_H

#include <stdint.h>

// CPU 使用率计算的上下文结构
struct cpu_usage_context {
    uint64_t last_cpu_ns;        // 上次采样的 CPU 时间
    uint64_t last_sample_time;   // 上次采样的时间戳
    int sample_count;            // 采样计数
};

// CPU 使用率计算结果
struct cpu_usage_result {
    double current_usage;        // 当前使用率
};

// 初始化 CPU 使用率计算上下文
void init_cpu_usage_context(struct cpu_usage_context *ctx);

// 计算 CPU 使用率
struct cpu_usage_result calculate_cpu_usage(
    struct cpu_usage_context *ctx,
    uint64_t current_cpu_ns,
    uint64_t current_time_ns,
    int num_cpus);

#endif /* CPU_CALCULATOR_H */