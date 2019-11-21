/*
**	parent and child processes execute same program, different codes
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(void) {
	pid_t pid = fork();
	if(pid < 0) {
		fprintf(stderr, "\nfork() failed\t-> errno = %d\n", errno);
		exit(-1);
	} else if(pid == 0) {
		execlp("/bin/ls", "ls", NULL);
		//execlp("./test", "test", NULL);
		// printf("\nChild process:\nfork() returned %d\npid = %d\nparent pid = %d\n", pid, getpid(), getppid());
		exit(0);
	} else {
		wait(NULL);
		printf("\nParent process:\nfork() returned %d\npid = %d\n", pid, getpid());
	}
	return 0;
}