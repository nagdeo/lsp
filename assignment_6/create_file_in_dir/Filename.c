#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]) 
{
	
	char name[1024] = {'\0'};
        int fd=0;
	
	if(argc!= 3)
	{
		printf("Error: Not sufficient arguments\n");
		return -1;
	}

        sprintf(name,"%s/%s", argv[1],argv[2]);
	fd=creat(name,0777);
        write(fd,"file is created",15);
     
        return 0;
}
