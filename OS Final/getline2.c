#include <stdio.h>
#include <stdlib.h>

FILE* getFilePointer(char* mode);
char* getLine(FILE* file, char* text, char delim);

int main(void) {
	FILE* fptr;
	char* line;
	char text[1000];

	fptr = getFilePointer("r");
	printf("\nGotten file name\n");
	putchar('\n');
	while(!feof(fptr)) {
		line = getLine(fptr, text, '\n');
		printf("%s\n", line);
	}
	return 0;
} 

FILE* getFilePointer(char* mode) {
	char* filename;

	printf("\nEnter the name of the file: ");
	scanf("%s", filename);
	return fopen(filename, mode);
}

char* getLine(FILE* file, char* text, char delim) {
	char ch;
	unsigned int i = 0;
	// char line[1000];

	while((ch = fgetc(file)) != EOF) {
		if(ch != delim) {
			text[i++] = ch;
		}
	}
	text[i] = '\0';
	return text;
}