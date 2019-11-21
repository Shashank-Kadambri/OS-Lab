#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int ID;
    int BT;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void enqueue(int id, int bt) {
    Node* p = malloc(sizeof(Node));
    p -> ID = id;
    p -> BT = bt;
    p -> next = NULL;
    if(head == NULL) {
        //printf("First Node\n");
        head = tail = p;
    } else {
        //printf("Subdequent Node\n");
        tail -> next = p;
        tail = p;
    }
    return;
}

void display(void) {
    Node* temp = head;
    if(temp != NULL) {
        printf("\n** Ready queue **\n");
        while(temp != NULL) {
            printf("P%d  ", temp -> ID);
            temp = temp -> next;
        }
    } else {
        printf("\n** No process present in ready queue **\n");
    }
}

void startExecution(void) {
    int turnaround_time = 0;
    float waiting_time = 0.0, total_waiting_time = 0.0;
    int count = 0;

    if(head != NULL) {
        Node* temp = head;
        Node* prev = head;
        while(temp != NULL) {
            prev = temp;
            printf("\nP%d running\n", temp -> ID);
            printf("Execution completed. Process terminated after %d bursts\n", temp -> BT);
            ++count;
            turnaround_time += temp -> BT;
            printf("Turnaround time = %d\n", turnaround_time);
            printf("Waiting time = %0.2f\n", waiting_time);
            if(temp != tail) {
                waiting_time += temp -> BT;
                total_waiting_time += waiting_time;
            }
            temp = temp -> next;
            if(prev == tail) {
                head = tail = NULL;
            }
            free(prev);
        }
        printf("\nAverage waiting time: %0.2f", total_waiting_time / count);
    } else {
        printf("\n** No processes present in ready queue **\n");
    }
    return;
}

int main(void) {
    int choice, id, bt;
    do {
        printf("\n\t\t****** FCFS Menu ******\n");
        printf("\t\t1. Add a process\n");
        printf("\t\t2. View ready queue\n");
        printf("\t\t3. Start execution\n");
        printf("\t\t4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        //printf("Your choice was: %d\n",choice);
        switch(choice) {
            case 1: printf("\nEnter process id: ");
                    scanf("%d", &id);
                    printf("Enter burst time: ");
                    scanf("%d", &bt);
                    enqueue(id, bt);
                    break;

            case 2: display();
                    break;

            case 3: startExecution();
                    break;

            default: if(choice != 4)
                        printf("INVALID CHOICE!!\n");
        }
        printf("\n\n\n");
    } while(choice != 4);
    return 0;
}