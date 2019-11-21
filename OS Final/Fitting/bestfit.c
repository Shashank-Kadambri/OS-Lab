#include <stdio.h>

#define MAX 20

int main(void) {
    int i, n, m, j;
    // int process[MAX], memblock[MAX];

    // printf("\nEnter the number of processes : ");
    // scanf("%d", &n);
    // printf("\nEnter the number of memory blocks : ");
    // scanf("%d", &m);
    // for(i = 0; i < n; ++i) {
    //     printf("\nEnter the size of process P[%d]: ", i + 1);
    //     scanf("%d", &process[i]);
    // }
    // for(i = 0; i < m; ++i) {
    //     printf("\nEnter the size of memory block %d: ", i + 1);
    //     scanf("%d", &memblock[i]);
    // }
    m = 5;
    n = 4;
    int process[] = {212, 417, 112, 426};
    int memblock[] = {100, 500, 200, 300, 600};

    int remaining_size[m];
    int k, smallest;
    for(i = 0; i < n; ++i) {
        for(j = 0, k = 0; j < m; ++j) {
            if(memblock[j] >= process[i]) {
                temp = memblock[j] - process[i];
                smallest = j;
            }
        }
        printf("\n*** k = %d ***\n", k);
        for(j = 0; j < k; ++j) {
            if(j == 0)
                smallest = j;
            if(remaining_size[smallest] > remaining_size[j]) {
                smallest = j;
            }
        }
        memblock[smallest] -= process[i];
        printf("\nProcess P[%d] of size %dKB allocated to memory block %d.\nRemaning size in block %d = %d\n", i + 1, process[i], smallest + 1, smallest + 1, memblock[smallest]);
    }

    // int remaining_size[m];
    // int smallest = 0;
    // for(i = 0; i < n; ++i) {
    //     int min = 0;
    //     for(j = 0; j < m; ++j) {
    //         remaining_size[j] = memblock[j] - process[i];
    //     }
    //     smallest = 0;
    //     for(j = 0; j < m; ++j) {
    //         if(remaining_size[j] < remaining_size[smallest] && remaining_size > 0) {
    //             smallest = j;
    //         }
    //     }
    //     memblock[smallest] -= process[i];
    //     printf("\nProcess P[%d] allocated to memory block %d.\nRemaning size in block %d = %d\n", i + 1, smallest + 1, smallest + 1, remaining_size[smallest]);
    // }

    // for(i = 0; i < n; ++i) {
    //     int min = 0;
    //     for(j = 0; j < m; ++j) {
    //         if(process[i] <= memblock[j]) {
    //             min = j;
    //             break;
    //         }
    //     }
    //     for(; j < m; ++j) {
    //         if(process[i] <= memblock[j]) {
    //             if(memblock[j] < memblock[min]) {
    //                 min = j;
    //             }    
    //         }
    //     }
    //     if(process[i] > memblock[min]) {
    //         printf("\n*** Insufficient memory for the process ***\n");    
    //     } else {
    //         memblock[min] -= process[i];
    //         printf("\nProcess P[%d] allocated to memory block %d.\nRemaining size in block %d = %d\n", i + 1, min + 1, min + 1, memblock[min]);
    //     }
    // }
    return 0;
}