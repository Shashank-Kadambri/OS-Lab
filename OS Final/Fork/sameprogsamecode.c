/*
**  parent and child processes execute same program, same code
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
    pid_t pid = fork();
    if(pid < 0) {
        fprintf(stderr, "\nfork() failed\t-> errno = %d\n", errno);
        exit(-1);
    } else {
        printf("\nfork returned %d\nsame code is being processed\npid = %d\nppid = %d\n", pid, getpid(), getppid());
    }
    return 0;
}    