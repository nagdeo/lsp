#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/types.h>
#include<stdio.h>
#include<fcntl.h>

#include<unistd.h>
#include<string.h>
int main(int argc, char *argv[]) 
{
	DIR *dir;
	struct dirent *entry;
	struct stat filestat;
	char name[100] = {'\0'};
        int fd=0,ret=0,fd1=0,dm=0;
	char arr[11],arr1[11];
	if(argc!= 2)
	{
		printf("Error: Not sufficient arguments\n");
		return -1;
	}


	fd=creat(argv[1],0777);
     
	
	
	// readdir() system call returns NULL when it reach end of the directory.

	// closedir() close the directory which is opened by opendir()
	closedir(dir);
        return 0;
}
