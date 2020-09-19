#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd=0;
    int iret=0,i=0;
   
    fd=open(argv[1],O_WRONLY);
 
    if(fd==-1){
      printf("Unable to open file\n");
    }
    else{
       printf("File opened successfully with fd: %d\n",fd);
    }
    
    iret=write(fd,argv[2],strlen(argv[2]));

    if(iret==-1){
      printf("Unable to write\n");
      close(fd);
      return -1;
    }
    printf("Data gets written in the file successfully\n");
    close(fd);
    return 0;
}
