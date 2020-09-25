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
         truncate(argv[1] , atoi(argv[2]));
         close(fd);

	

        return 0;
}
