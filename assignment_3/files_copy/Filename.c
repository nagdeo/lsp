#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>

#include <sys/stat.h>

#include <dirent.h>
int main(int argc, char *argv[]){

    int fd=0,fw=0;
    int ret=0;
    char arr[11];
   fd=open(argv[1],O_RDONLY);
   fw=open(argv[2],O_RDWR);
   if(fd==-1){
     printf("Unable to open file\n");
     return -1;
   }
   printf("Copying contents of file %s",argv[1]);
   printf(" to file %s",argv[2]);
    while((ret=read(fd,arr,10))!=0){
      
     write(fw,arr,ret);
   }

    close(fd);
   
  return 0;
}
