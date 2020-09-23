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
        int fd=0,ret=0,fd1=0,dm=0,allcom=0;
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

	fd=creat("AllCombine.txt",0777);
       // printf("Demo %d",fd);
        allcom=open("AllCombine.txt",O_RDWR | O_APPEND);
	while ((entry = readdir(dir)) != NULL)
	{
		// Create absolute path
	        sprintf(name,"%s/%s", argv[1],entry->d_name);
		stat(name,&filestat);
			
		if(S_ISREG(filestat.st_mode)){
                    fd1=open(name,O_RDWR);
                   
                    while((ret=read(fd1,arr,10))!=0){
                      write(allcom,arr,ret);
                    }
                    
                   
                }
			
		
	}
         dm=open("AllCombine.txt",O_RDONLY);
         printf("Contents of AllCombine.txt is: \n");
         while((ret=read(dm,arr1,10))!=0){
           write(1,arr1,ret);
         }
	
	// readdir() system call returns NULL when it reach end of the directory.

	// closedir() close the directory which is opened by opendir()
	closedir(dir);
        return 0;
}
