#include <stdio.h>

#define MAX 10

int main(void) {
    int at[MAX], bt[MAX], rt[MAX];
    int completion_time, i, smallest;
    int remain, n, time;
    float sum_wait = 0.0, sum_turnaround = 0.0;
    
    printf("\nEnter the no. of processes : ");
    scanf("%d", &n);
    remain = n;
    for(i = 0; i < n; ++i) {
        printf("\nEnter arrival time for process P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    rt[9] = 9999;
    // smallest contains the index of the process to be executed 
    printf("\n\nProcess\t|Turnaround Time| Waiting Time\n");
    for(time = 0; remain != 0; ++time) {
        smallest = 9;
        for(i = 0; i < n; ++i) {
            if((at[i] <= time) && (rt[i] <= rt[smallest]) && (rt[i] > 0)) {
                smallest = i;
            }
        }
        --rt[smallest];
        if(rt[smallest] == 0) {
            --remain;
            completion_time = time + 1;
            printf("\nP[%d]\t|\t%d\t|\t%d", smallest + 1, completion_time - at[smallest], completion_time - bt[smallest] - at[smallest]);
            sum_wait += completion_time - bt[smallest] - at[smallest];
            sum_turnaround += completion_time - at[smallest];
        }
    }
    printf("\n\nAverage waiting time = %0.2f\n", sum_wait / n);
    printf("Average Turnaround time = %0.2f\n", sum_turnaround / n);
    return 0;
}
