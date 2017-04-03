#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "mutex.h"

// Initialize the mutex. Technically unnecessary.
void mutex_init(mutex_m *mutex) {
    mutex->flag = 0;
}

// Acquire the mutex. Implemented in x86 with a spinlock.
// TODO: better to use memory instead of passing flag?
void mutex_lock(mutex_m *mutex) {
    assert(mutex != NULL);
    asm volatile(
        "MUTEX_ACQUIRE_LOCK:\n\t"
            "MOV $1, %%AL\n\t"
            "XCHG %0, %%AL\n\t"
            "CMP $0, %%AL\n\t"
            "JNE MUTEX_ACQUIRE_LOCK"
        : "=m" (mutex->flag) // output (%0), correct to be an earlyclobber?
        : "0" (mutex->flag)   // input (%1)
        : "rax"               // clobbers
    );
}

void mutex_unlock(mutex_m *mutex) {
    assert(mutex != NULL);
    asm volatile(
        "MOV $0, %%AL\n\t"
        "XCHG %0, %%AL"
        : "=m" (mutex->flag)
        : // no inputs
        : "rax"
    );
}
