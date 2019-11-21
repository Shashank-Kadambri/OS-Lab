#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/ipc.h>

#define SIZE 1024
#define BUFFER_SIZE 5

struct Shared {
	int buffer[BUFFER_SIZE];
	int in;
	int out;
};

int main(void) {
	int flag = 1;
	int key = 9010;
	int shmid;

	shmid = shmget(key, SIZE, IPC_CREAT | 0666);
	struct Shared* m = shmat(shmid, NULL, 0);
	m -> in = m -> out = 0;
	while(flag) {
		while((((m -> in) + 1) % BUFFER_SIZE) == (m -> out)); // if the buffer is full
		printf("Enter data to buffer: ");
		scanf("%d", &m -> buffer[(m -> in)]);
		(m -> in) = ((m -> in) + 1) % BUFFER_SIZE;
		printf("Produce more? (0 to stop)\n");
		scanf("%d", &flag);
	}
	shmdt(m);
	return 0;
}