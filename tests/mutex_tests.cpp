#include <pthread.h>
#include <unistd.h>

#include "gtest/gtest.h"

extern "C" {
    #include "mutex.h"
}


// Pthread that spins until it acquires a lock, then releases it.
void * SimpleBlockingThread(void *mutex) {
    mutex_m *m = (mutex_m *) mutex;
    mutex_lock(m);
    sleep(1);
    mutex_unlock(m);
    pthread_exit(NULL);
}

TEST(TestAcquireMutex, LockNotSetInitially) {
    mutex_m m;
    mutex_init(&m);
    mutex_lock(&m);
    EXPECT_EQ(m.flag, 1);
}

// Tests "releasing" unlocked locks.
TEST(TestReleaseMutex, LockNotSetInitially) {
    mutex_m m;
    mutex_init(&m);
    m.flag = 0;
    mutex_unlock(&m);
    EXPECT_EQ(m.flag, 0);
}

TEST(TestReleaseMutex, LockSetInitially) {
    mutex_m m;
    mutex_init(&m);
    m.flag = 1;    // assume we acquired the lock safely.
    mutex_unlock(&m);
    EXPECT_EQ(m.flag, 0);
}

// Thread should wait on us to release the lock.
// TODO: doesn't exit yet.
TEST(TestAcquireAndReleaseMutex, LockSetInitially) {
    mutex_m m;
    mutex_init(&m);
    // m.flag = 1;  // assume we acquired the lock safely.

    int err = 0;
    pthread_t thread;
    err = pthread_create(&thread, NULL, SimpleBlockingThread, (void *)(&m));
    EXPECT_EQ(err, 0);
    sleep(1);
    mutex_lock(&m);

    // mutex_unlock(&m);
    pthread_exit(NULL); // wait for thread to finish
    EXPECT_EQ(m.flag, 1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
