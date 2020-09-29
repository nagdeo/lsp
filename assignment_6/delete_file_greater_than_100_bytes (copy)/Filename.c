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

	// Open the directory
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	
	while ((entry = readdir(dir)) != NULL)
	{
		// Create absolute path
	        sprintf(name,"%s/%s", argv[1],entry->d_name);
		stat(name,&filestat);
			
		if(filestat.st_size>100){
                     unlink(name);
                }
			
		
	}
       
	// readdir() system call returns NULL when it reach end of the directory.

	// closedir() close the directory which is opened by opendir()
	closedir(dir);
        return 0;
}
