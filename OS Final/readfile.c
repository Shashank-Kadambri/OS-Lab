#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char text[1000], filename[50];
	FILE *fptr;

	printf("Enter the name of the file to be read: ");
	scanf("%s", filename);
	fptr = fopen(filename, "r");
	if(fptr == NULL) {
		fprintf(stderr, "\nError opening %s!", filename);
		exit(1);
	}
	
	fscanf(fptr,"%[^\n]",text);
	printf("\nContents of the file:\n\n%s", text);
	
	// for(int i = 0; text[i] != '\0'; ++i) {
	// 	printf("%c",text[i]);
	// }
	
	putchar('\n');
	fflush(stdout);
	fclose(fptr);
	
	return 0;
}
	
	
