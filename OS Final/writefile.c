#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char text[1000], filename[50];
	FILE *fptr;

	printf("Enter the name of the file to be written to: ");
	scanf("%s", filename);
	fptr = fopen(filename, "w");
	if(fptr == NULL) {
		fprintf(stderr, "\nError opening %s!", filename);
		exit(EXIT_FAILURE);
	}
	printf("Enter the text to be written to the file:\n\n");
	scanf(" %[^\n]",text);
	fprintf(fptr,"%s",text);
	
	printf("\nText successfully written to %s!", filename);
	putchar('\n');
	fflush(stdout);
	
	fclose(fptr);
	return 0;
}
	
