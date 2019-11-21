#include <stdio.h>

int main(void) {
    int i, n, m, j;
    printf("\nEnter the number of processes : ");
    scanf("%d", &n);
    printf("\nEnter the number of memory blocks : ");
    scanf("%d", &m);
    int process[n], memblock[m];
    for(i = 0; i < n; ++i) {
        printf("\nEnter the size of process P[%d] : ", i + 1);
        scanf("%d", &process[i]);
    }
    for(i = 0; i < m; ++i) {
        printf("\nEnter the size of memory block %d : ", i + 1);
        scanf("%d", &memblock[i]);
    }
    for(i = 0; i < n; ++i) {
        int max = 0;
        for(j = 1; j < m; ++j) {
            if(process[i] <= memblock[j]) {
                if(memblock[j] > memblock[max]) {
                    max = j;
                }    
            }
        }
        if(process[i] > memblock[max]) {
            printf("\n*** Insufficient memory for the process ***\n");    
        } else {
            memblock[max] -= process[i];
            printf("\nProcess P[%d] allocated to memory block %d.\nRemaining size in block %d = %d\n", i + 1, max + 1, max + 1, memblock[max]);
        }
    }

}