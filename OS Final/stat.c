#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

void printFilePermissions(struct stat* st) {
	printf("File Permissions: \t");
    printf((S_ISDIR(st->st_mode)) ? "d" : "-");
    printf((st->st_mode & S_IRUSR) ? "r" : "-");
    printf((st->st_mode & S_IWUSR) ? "w" : "-");
    printf((st->st_mode & S_IXUSR) ? "x" : "-");
    printf((st->st_mode & S_IRGRP) ? "r" : "-");
    printf((st->st_mode & S_IWGRP) ? "w" : "-");
    printf((st->st_mode & S_IXGRP) ? "x" : "-");
    printf((st->st_mode & S_IROTH) ? "r" : "-");
    printf((st->st_mode & S_IWOTH) ? "w" : "-");
    printf((st->st_mode & S_IXOTH) ? "x" : "-");
}

void printFileType(struct stat* st) {
	switch(st -> st_mode & S_IFMT) {
		case S_IFBLK : printf("block device\n");            
						break;
    	case S_IFCHR : printf("character device\n");
    			        break;
    	case S_IFDIR : printf("directory\n");               
    					break;
    	case S_IFIFO : printf("FIFO/pipe\n"); 
    	       	 	    break;
    	case S_IFLNK : printf("symlink\n");
    	                break;
    	case S_IFREG : printf("regular file\n"); 
    		            break;
    	case S_IFSOCK : printf("socket\n");                 
    					break;
    	default : printf("unknown?\n");    
    }
    return;
}

void printFileInfo(struct stat* st, char* filename) {
	printf("\nInformation for %s\n", filename);
	printf("-----------------------------------------------\n");
	printf("File type:\t\t");
	printFileType(st);
	printf("File size: \t\t%ld bytes\n", st -> st_size);
	printf("Number of links: \t%ld\n", st -> st_nlink);
    printf("File inode: \t\t%ld\n", st -> st_ino);
    printf("Block size: \t\t%ld\n", st -> st_blksize);
    printf("No. of blocks allocated:%ld\n", st -> st_blocks);
    printf("Last status change: \t%s", ctime(&st -> st_ctime)); 
    printf("Last file access: \t%s", ctime(&st -> st_atime)); 
    printf("Last file modification: %s", ctime(&st -> st_mtime)); 	
}

int main(int argc, char** argv) {
	int f_d = 0;
	struct stat st;

	if(argc != 2) {
		return -1;
	}

	f_d = open(argv[1], O_RDONLY);
	if(f_d == -1) {
		fprintf(stderr, "\nNULL File descriptor.\n");
		exit(EXIT_FAILURE);
	}
	// printf("errno = %d\n", errno);
	if(fstat(f_d, &st) == -1) {
		fprintf(stderr, "fstat error: %s\n", strerror(errno));
		close(f_d);
		exit(-1);
	}
	printFileInfo(&st, argv[1]); 
    printFilePermissions(&st);
    printf("\n\n");

	close(f_d);
	return 0;
}