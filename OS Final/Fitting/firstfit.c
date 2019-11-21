#include <stdio.h>

#define MAX 20

int main(void) {
    int process[MAX], memblock[MAX];
    int i, n, m, j;
    printf("\nEnter the number of processes : ");
    scanf("%d", &n);
    printf("\nEnter the number of memory blocks : ");
    scanf("%d", &m);
    for(i = 0; i < n; ++i) {
        printf("\nEnter the size of process P[%d] : ", i + 1);
        scanf("%d", &process[i]);
    }
    for(i = 0; i < m; ++i) {
        printf("\nEnter the size of memory block %d : ", i + 1);
        scanf("%d", &memblock[i]);
    }
    for(i = 0; i < n; ++i) {
        for(j = 0;j < m; ++j) {
            if(process[i] <= memblock[j]) {
                memblock[j] -= process[i];
                printf("\nProcess P[%d] allocated to memory block %d.\nRemaining size in block %d = %d\n", i + 1, j + 1, j + 1, memblock[j]);
                break;
            }
        }
        if(j == m)
            printf("\n*** Insufficient memory for the process ***\n");
    }
    return 0;
}