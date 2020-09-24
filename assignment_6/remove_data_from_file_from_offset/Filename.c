#include <stdio.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]) 
{

	char name[100] = {'\0'};
        int fd=0,fd1=0;
	char arr[atoi(argv[2])+1];
	if(argc!= 3)
	{
		printf("Error: Not sufficient arguments\n");
		return -1;
	}
         fd=open(argv[1],O_RDONLY);
         printf("File gets successfully opened with fd : %d\n",fd);
         read(fd,arr,atoi(argv[2]));
         unlink(argv[1]);
         fd1=creat(argv[1],0777);
         printf("Those bytes are as follows: \n");
         write(fd1,arr,atoi(argv[2])); 
         close(fd);

	

        return 0;
}
