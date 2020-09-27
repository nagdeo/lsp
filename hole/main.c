#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){

    int fd=0,ret=0;
    fd=open(argv[1],O_RDWR);
    if(fd==-1){

     }
     ret=lseek(fd,1024,SEEK_END);
     write(fd," ",1);
     close(fd);
  
  return 0;
}

