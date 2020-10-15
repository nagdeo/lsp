#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(
         int argc, char *argv[]
        )
{
    int fd=0;
    int iret=0;
    char arr[11]="Marvellous";
   
    fd=open(argv[1],O_WRONLY);
    if(fd==-1){
      printf("Unable to open file\n");
    }
    else{
       printf("File opened successfully with fd: %d\n",fd);
    }
    
    iret=write(fd,arr,10);

    if(iret==-1){
      printf("Unable to write\n");
      close(fd);
      return -1;
    }
    printf("Data gets written in the file successfully\n");
    close(fd);
    return 0;
}
