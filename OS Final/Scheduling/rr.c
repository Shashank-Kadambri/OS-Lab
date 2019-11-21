#include <stdio.h>

#define MAX 10 
 
int main(void) { 
      int i, n, time = 0, remain, flag = 0, time_quantum; 
      int bt[MAX], rt[MAX];
      float total_wt = 0.0, total_tat = 0.0; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter the total number of processes : "); 
      scanf("%d", &n); 
      remain = n; 
      for(i = 0; i < n; i++) {
            printf("\nEnter details for process P[%d]:\n", i + 1);
            // printf("arrival time : ");
            // scanf("%d", &at[i]);
            printf("burst time : ");
            scanf("%d", &bt[i]); 
            rt[i] = bt[i];
      } 
      printf("\nEnter the time quantum : "); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");

      for(time = 0, i = 0; remain != 0;) { 
            if(rt[i] <= time_quantum && rt[i] > 0) { 
                  time += rt[i]; 
                  rt[i] = 0; 
                  flag = 1; 
            } else if(rt[i] > 0) { 
                  rt[i] -= time_quantum; 
                  time += time_quantum; 
            } 
            if(rt[i] == 0 && flag == 1) { 
                  --remain; 
                  printf("\nP[%d]\t\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], time, time - bt[i]);
                  total_wt += time - bt[i]; 
                  total_tat += time; 
                  flag = 0; 
            } 
            if(i == n - 1) {
                  i = 0; 
            // } else if(at[i + 1] <= time) {
            //       i++;
            } else {
                  // i = 0;
                  ++i;
            }
      } 
      printf("\n\nAverage waiting time = %0.2f", total_wt / n); 
      printf("\nAverage turnaround time = %0.2f\n", total_tat / n); 
      return 0; 
}