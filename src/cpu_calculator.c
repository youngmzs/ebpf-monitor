#include <string.h>
#include "cpu_calculator.h"

#define HIGH_THRESHOLD 80.0
#define LOW_THRESHOLD 20.0

void init_cpu_usage_context(struct cpu_usage_context *ctx) {
    memset(ctx, 0, sizeof(struct cpu_usage_context));
}

struct cpu_usage_result calculate_cpu_usage(
    struct cpu_usage_context *ctx,
    uint64_t current_cpu_ns,
    uint64_t current_time_ns,
    int num_cpus)
{
    //num_cpus没用到，单线程的利用率没必要平均到多核
    struct cpu_usage_result result = {0};
    // 计算上一次时间采样时间差
    uint64_t time_delta = current_time_ns - ctx->last_sample_time;
    if (time_delta == 0) {
        return result;
    }
    // 计算ON CPU的时间
    uint64_t cpu_delta = current_cpu_ns - ctx->last_cpu_ns;
    
    // 计算这个采样周期的CPU使用率 = ON CPU TIME / ALL TIME
    double current_usage = ((double)cpu_delta / time_delta) * 100.0;
    
    // 多核心情况，暂时不考虑
    /*if (num_cpus > 1) {
        current_usage = current_usage / num_cpus;
    }*/

    // 更新上下文
    ctx->last_cpu_ns = current_cpu_ns;
    ctx->last_sample_time = current_time_ns;
    // 填充当前CPU时间
    result.current_usage = current_usage;
    return result;
}