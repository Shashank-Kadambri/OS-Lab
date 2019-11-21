#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help() {
	fprintf(stderr, "\ncp: command line error\nTry './cp --help' for more information.\n");
	exit(EXIT_FAILURE);
}

char* switch_check(int argnum, char* arg) {
	if(argnum == 2) {
		if(strcmp(arg, "-w") == 0 || strcmp(arg, "-a") == 0) {
			fprintf(stderr, "\ncp: missing file operand\nTry './cp --help' for more information.\n");
			exit(EXIT_FAILURE);
		} else {
			fprintf(stderr, "\ncp: invalid switch '%s'\nTry './cp --help' for more information.\n", arg);
			exit(EXIT_FAILURE);
		}
	} else {
		if((strcmp(arg, "-w") == 0)) {
			return "w";
		} else if((strcmp(arg, "-a") == 0)) {
			return "a+";
		} else {
			fprintf(stderr, "\ncp: invalid switch '%s'\nTry './cp --help' for more information.\n", arg);
			exit(EXIT_FAILURE);
		}
	} 
}

int main(int argc, char** argv) {
	char* file_mode;
	char* srcfile;
	char* destfile;
	FILE* fptr1;
	FILE* fptr2;
	char ch;

	switch(argc) {
		case 1 : {
			fprintf(stderr, "\ncp: missing file operand\nTry './cp --help' for more information.\n");
			exit(EXIT_FAILURE);
		}
		break;

		case 2 : {
			if(strcmp(argv[1], "--help") == 0) {
				printf("Usage: cp [SWITCH] [SOURCE FILE] [DESTINATION FILE]\n");
				printf("   or: cp [SOURCE FILE] [DESTINATION FILE]\n");
				printf("Copies SOURCE FILE to DESTINATION FILE.\n\n");
				printf("  -w          creates DESTINATION FILE, if already exists, overwrites\n");
				printf("  -a          creates DESTINATION FILE, if already exists, appends\n");
				printf("              contents of SOURCE FILE to DESTINATION FILE\n");
			} else if(argv[1][0] == '-') {
				switch_check(argc, argv[1]);
			} else {
				fprintf(stderr, "\ncp: missing destination file operand after '%s'\n", argv[1]);
				fprintf(stderr, "Try './cp --help' for more information.\n");
				exit(EXIT_FAILURE);
			} 
		}
		break;

		case 3 : {
			srcfile = argv[1];
			destfile = argv[2];

			if((fptr1 = fopen(srcfile, "r")) == NULL) {
				fprintf(stderr, "\ncp: '%s': No such file or directory\n", srcfile);
				exit(EXIT_FAILURE);
			}
			if((fptr2 = fopen(destfile, "w")) == NULL) {
				fprintf(stderr, "\ncp: error creating '%s'\n", destfile);
				fclose(fptr1);
				exit(EXIT_FAILURE);
			}

			while((ch = fgetc(fptr1)) != EOF) {
				fputc(ch, fptr2);
			}
			printf("\ncp: contents of '%s' copied to '%s' successfully", srcfile, destfile);
		}
		break;

		case 4 : {
			srcfile = argv[2];
			destfile = argv[3];

			if(argv[1][0] == '-') {
				file_mode = switch_check(argc, argv[1]);
			} else {
				print_help();
			}

			if((fptr1 = fopen(srcfile, "r")) == NULL) {
				fprintf(stderr, "\ncp: '%s': No such file or directory\n", srcfile);
				exit(EXIT_FAILURE);
			}
			if((fptr2 = fopen(destfile, file_mode)) == NULL) {
				fprintf(stderr, "\ncp: error creating '%s'\n", destfile);
				fclose(fptr1);
				exit(EXIT_FAILURE);
			}

			while((ch = fgetc(fptr1)) != EOF) {
				fputc(ch, fptr2);
			}

			if(strcmp(file_mode, "a+") == 0) {
				printf("\ncp: contents of '%s' appended to '%s' successfully", srcfile, destfile);
			} else {
				printf("\ncp: contents of '%s' copied to '%s' successfully", srcfile, destfile);		
			}
		}
		break;

		default: {
			print_help();
		}
	}
	putchar('\n');
	return 0;
}