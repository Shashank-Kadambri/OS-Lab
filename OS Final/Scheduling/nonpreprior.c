/*
	arrival time is assumed to be 0 for all the processes
	higher the number, higher the priority
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int pid;
	int burst_time;
	int priority;
	struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void addProcessToReadyQueue(int id, int bt, int prio) {
	struct Node* temp = malloc(sizeof(struct Node));
	temp -> pid = id;
	temp -> burst_time = bt;
	temp -> priority = prio;
	temp -> next = NULL;
	if(head == NULL) {
		head = tail = temp;
	} else {
		if(prio > head -> priority) {
			temp -> next = head;
			head = temp;
		} else if(prio < tail -> priority) {
			tail -> next = temp;
			tail = temp;
		} else {
			struct Node* ptr = head;
			while((ptr -> next != NULL) && (prio < ptr -> next -> priority)) {
				ptr = ptr -> next;
			}
			temp -> next = ptr -> next;;
			ptr -> next = temp;
		}
	}
	return;
}

void destroyQueue(void) {
	struct Node* temp = head;
	while(temp != NULL) {
		struct Node* nextnode = temp -> next;
		free(temp);
		temp = nextnode;
	}
	head = tail = NULL;
	return;
}

void startExecution(void) {
	struct Node* temp = head;
	struct Node* prev = head;
	int count = 0;
	float tat = 0.0, totaltat = 0.0, wt = 0.0, totalwt = 0.0;  
	if(head == NULL) {
		printf("\n*** No processes present in the ready queue ***\n");
	} else {
		while(temp != NULL) {
			prev = temp;
			printf("\nExeceuting process P%d...\n", temp -> pid);
			printf("Burst time = %dms\n", temp -> burst_time);
			printf("Priority = %d\n", temp -> priority);
			tat = tat + temp -> burst_time;
			totaltat += tat;
			wt = tat - prev -> burst_time;
			totalwt += wt;
			printf("Turnaround time = %0.2fms\n", tat);
			printf("Waiting time = %0.2fms\n", wt);
			++count;
			temp = temp -> next;
		}
		printf("\nAverage turnaround time = %0.2fms\n", totaltat / count);
		printf("Average waiting time = %0.2fms\n", totalwt / count);
	}
	destroyQueue();
	return;
}

void displayReadyQueue(void) {
	struct Node* temp = head;
	if(head == NULL) {
		printf("\n*** No processes present in the ready queue ***\n");
	} else {
		printf("\nReady queue:\n");
		while(temp != NULL) {
			printf("P%d  ", temp -> pid);
			temp = temp -> next;
		}
	}
	return;
}

int main(void) {
	int choice, id, bt, prio;
	do {
		printf("\n\t\t*** Non-Preemptive Priority Scheduling ***\n\n\t\t");
		printf("1. Add a process\n\t\t");
		printf("2. View ready queue\n\t\t");
		printf("3. Start execution\n\t\t");
		printf("4. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1 : {
				printf("\nEnter the process ID : ");
				scanf("%d", &id);
				printf("Enter burst time : ");
				scanf("%d", &bt);
				printf("Enter the priority : ");
				scanf("%d", &prio);
				addProcessToReadyQueue(id, bt, prio);
			} break;

			case 2 : {
				displayReadyQueue();
			} break;

			case 3 : {
				startExecution();
			} break;

			default : {
				if(choice != 4)
					printf("\nINVALID CHOICE!");
			}
		}
		printf("\n\n");
		for(int i = 0; i < 80; ++i) {
			printf("*");
		}
		printf("\n\n\n");
	} while(choice != 4);
	destroyQueue();
	return 0;
}