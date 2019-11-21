#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define BUFFER_SIZE 5
#define SIZE 1024

struct Shared {
	int buffer[BUFFER_SIZE];
	int in;
	int out;
};

int main(void) {
	int flag = 1;
	int key = 9010;
	int shmid;

	// creating a shared memory area and getting its id
	shmid = shmget(key, SIZE, IPC_CREAT | 0666);
	// attaching the shared memory area to the calling process
	struct Shared* m = shmat(shmid, NULL, 0);
	m -> in = m -> out = 0;
	while(flag) {
		while((m -> in) == (m -> out));	// if the buffer is empty
		printf("\nData consumed from buffer: %d", m -> buffer[(m -> out)]); 
		//scanf("%d",m->buffer[in]);
		(m -> out) = ((m -> out) + 1) % BUFFER_SIZE;
		printf("\nConsume more? (0 to stop): ");
		scanf("%d", &flag);
	}
	shmdt(m);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}