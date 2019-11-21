/*
**	Inter Process Communication between parent and child process using pipe system call
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define WRITE_END 1
#define READ_END 0

int main(void) {
	char write_msg[BUFFER_SIZE] = "Hello World!";
	char read_msg[BUFFER_SIZE];
	int fd[2];
	pid_t pid;

	if(pipe(fd) == -1) {
		fprintf(stderr, "\nERROR: pipe() failed\t-> errno = %d\n", errno);
		exit(-1);
	}
	pid = fork();
	if(pid < 0) {
		fprintf(stderr, "\nfork() failed\t-> errno = %d\n", errno);
		exit(-2);
	} else if(pid > 0) {
		// in parent process
		// printf("\nParent: Child PID = %d\n", pid);
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
		close(fd[WRITE_END]);
	} else { 
		// child process
		// printf("\nChild: Child PID = %d\n", getpid());
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("read:\n%s\n", read_msg);
		close(fd[READ_END]);
	}
	return 0;
}