#pragma once

#include <stdint.h>

// Binary semaphore
typedef struct mutex_m {
    uint32_t flag;
} mutex_m;

// Counting semaphore
typedef struct semaphore_m {
    uint32_t flag;
} semaphore_m;

void mutex_init(mutex_m *mutex);
void mutex_lock(mutex_m *mutex);
void mutex_unlock(mutex_m *mutex);

void semaphore_acquire(semaphore_m *sem);
void semaphore_release(semaphore_m *sem);
