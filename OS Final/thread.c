#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

long count = 0;

void* runner(void* param) {
    // perform some work
    for(long i = 0; i < 200000; ++i)
        ++count;
    return NULL;
}

int main(void) {
    int var = 15;
    pthread_t tid, tid2;
    pthread_create(&tid, NULL, runner, NULL);
    pthread_join(tid, NULL);
    pthread_create(&tid2, NULL, runner, NULL);
    //pthread_join(tid,NULL);
    pthread_join(tid2, NULL);
    printf("count: %li\n", count);
    return 0;
}