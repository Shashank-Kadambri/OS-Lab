#include <stdio.h>
#include <stdlib.h>

const char* getLine(FILE* stream, char* line, char delim) {
    char* ptr;
    ptr = fgets(line, 1001, stream);
    if(ptr != NULL) {
        return ptr;
    } else {
        return "Error!";
    }
}

int main(void) {
    // system("pause");
    // for(unsigned int i = 0; i < 3; ++i) {
    //     printf("The value of variable i is: %f\n", (float)i);
    // }

    // char line[100];
    // printf("Enter some text:\n");
    // fgets(line, 101, stdin);
    // printf("\n\nEntered line:\n%s", line);

    char line[1000];
    printf("Enter some text:\n");
    const char* text = getLine(stdin, line);
    printf("\n\nEntered text:\n%s", text);
    return 0;
}