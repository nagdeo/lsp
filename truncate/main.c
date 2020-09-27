#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){

    int fd=0,ret=0;

    ret=truncate(argv[1],105);
 
   
    if(ret==-1){
       printf("unable to truncate");
         return -1;
     }
      printf("%d",ret);
    
      fd=open("temp.txt",O_WRONLY);
     ret=ftruncate(fd,15);
     close(fd);
  
  return 0;
}

