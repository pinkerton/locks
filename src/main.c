#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "mutex.h"

void * SimpleBlockingThread(void *mutex) {
    mutex_m *m = (mutex_m *) mutex;
    printf("Spinning...\n");
    mutex_lock(m);
    printf("Acquired lock\n");
    sleep(1);
    printf("Released lock\n");
    mutex_unlock(m);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    mutex_m m;
    mutex_init(&m);
    mutex_lock(&m);
    // m.flag = 1;  // assume we acquired the lock safely.

    int err = 0;
    pthread_t thread;
    err = pthread_create(&thread, NULL, SimpleBlockingThread, (void *)(&m));
    assert(err == 0);

    mutex_unlock(&m);
    pthread_exit(NULL); // wait for thread to finish
    assert(m.flag == 0);
    
    printf("All done\n");

    exit(0);
}

