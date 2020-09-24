#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]) 
{
        int fd=0,size=0;
         char ch[20]="hello world how are";
	
	if(argc!= 2)
	{
		printf("Error: Not sufficient arguments\n");
		return -1;
	}
         fd=open(argv[1],O_RDWR|O_APPEND);
         printf("File gets successfully opened with fd : %d\n",fd);
          system("chmod 777 hello");
        // size=lseek(fd,0,SEEK_END);
        // printf("%d",size);
         lseek(fd,50,SEEK_SET);
         write(fd,ch,19);
         close(fd);

	

        return 0;
}
