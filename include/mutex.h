#pragma once

typedef struct mutex_m {
    uint32_t flag;
} mutex_m;

void mutex_init(mutex_m *mutex);
void mutex_lock(mutex_m *mutex);
void mutex_unlock(mutex_m *mutex);
