#include <stdio.h>
#include <stdlib.h>
#include "cgroup_config.h"

#define HIGH_THRESHOLD 80.0
#define LOW_THRESHOLD 20.0
#define MIN_QUOTA_PERCENT 10.0
#define MAX_QUOTA_PERCENT 1000.0

// 调整 cgroup 的 CPU 配额，就是简单的计数然后调整
static void adjust_cgroup_quota(struct target_cgroup *cgroup)
{
    if (cgroup->high_count >= 3) {
        printf("adjust_cgroup_quota to high cgroup %s quota\n",cgroup->path);
        // 增加配额
        double new_quota = cgroup->current_quota * 1.1;  // 增加 10%
        if (new_quota <= MAX_QUOTA_PERCENT) {
            char cmd[512];
            snprintf(cmd, sizeof(cmd),
                    "echo %d %d > %s/cpu.max",
                    (int)(new_quota * 1000), 100000, cgroup->path);
            //直接写cgroup v2的cpu.max文件，提高配额
            if (system(cmd) == 0) {
                printf("Increased CPU quota for %s from %.1f%% to %.1f%%\n",
                       cgroup->path, cgroup->current_quota, new_quota);
                cgroup->current_quota = new_quota;
            }
        }
        cgroup->high_count = 0;
    }
    else if (cgroup->low_count >= 3) {
        // 减少配额
        printf("adjust_cgroup_quota to low cgroup %s quota\n",cgroup->path);
        double new_quota = cgroup->current_quota * 0.9;  // 减少 10%
        if (new_quota >= MIN_QUOTA_PERCENT) {
            char cmd[512];
            //直接写cgroup v2的cpu.max文件，进行配额降低
            snprintf(cmd, sizeof(cmd),
                    "echo %d %d > %s/cpu.max",
                    (int)(new_quota * 1000), 100000, cgroup->path);

            if (system(cmd) == 0) {
                printf("Decreased CPU quota for %s from %.1f%% to %.1f%%\n",
                       cgroup->path, cgroup->current_quota, new_quota);
                cgroup->current_quota = new_quota;
            }
        }
        cgroup->low_count = 0;
    }
}

// 更新 cgroup 的使用统计，用统计数据来决策使用率的调整
void update_cgroup_stats(struct target_cgroup *cgroup, double cpu_usage)
{
    // 更新使用统计，超过三次或小于两次的策略，顺序计数
    if (cpu_usage >= HIGH_THRESHOLD) {
        cgroup->high_count++;
        cgroup->low_count = 0;
    } else if (cpu_usage <= LOW_THRESHOLD) {
        cgroup->low_count++;
        cgroup->high_count = 0;
    } else {
        cgroup->high_count = 0;
        cgroup->low_count = 0;
    }
    // 调整配额
    adjust_cgroup_quota(cgroup);
}