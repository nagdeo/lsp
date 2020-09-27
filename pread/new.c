#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){

    int fd=0,ret=0;
    char buffer[30];
    
    fd=open("data.txt",O_RDONLY);
 
   
    if(fd==-1){
       printf("unable to ");
         return -1;
     }
     //lseek(fd,10,SEEK_SET);
     
     //ret=read(fd,buffer,30);
     
     ret = pread(fd,buffer,30,10);
     //1:File descriptor
     //2:address of buffer
     //3:np of bytes to read
     //4:offset from where we want to read(new parameter)

     printf("Data is \n");
      
     write(1,buffer,ret);
   
    close(fd);
  
    return 0;
}
/*
  concept->
     here in between lseek and read system call , if another process had changed the data of that file we get different data,
     This 2(lseek and read) system calls are not atomic(not together).
     if after lseek kernel goes to another process and change data (kernel goes to another process after 1 system call complete,  not while executing one system call, but agter lseek gets
      executed then kernel can go to another process.)

     so to do atomic operation ,linux had introduced pread for lseek and read to become atomic
     pread is wrapper
*/
