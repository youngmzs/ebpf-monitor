#include <string.h>
#include <stdio.h>
#include "cgroup_config.h"

void init_cgroup_config(struct cgroup_monitor_config *config)
{
    memset(config, 0, sizeof(struct cgroup_monitor_config));
}

int add_target_cgroup(struct cgroup_monitor_config *config, const char *cgroup_path)
{
    if (config->cgroup_count >= MAX_TARGET_CGROUPS) {
        return -1;
    }
    
    struct target_cgroup *target = &config->cgroups[config->cgroup_count];
    strncpy(target->path, cgroup_path, MAX_CGROUP_PATH - 1);
    target->path[MAX_CGROUP_PATH - 1] = '\0';
    target->current_quota = 100.0;  // 初始配额 100%
    
    config->cgroup_count++;
    return 0;
}

bool is_target_cgroup(struct cgroup_monitor_config *config, const char *cgroup_path)
{
    for (int i = 0; i < config->cgroup_count; i++) {
        if (strcmp(config->cgroups[i].path, cgroup_path) == 0) {
            return true;
        }
    }
    return false;
}

struct target_cgroup *get_target_cgroup(struct cgroup_monitor_config *config, 
                                      const char *cgroup_path)
{
    for (int i = 0; i < config->cgroup_count; i++) {
        if (strcmp(config->cgroups[i].path, cgroup_path) == 0) {
            return &config->cgroups[i];
        }
    }
    return NULL;
}
