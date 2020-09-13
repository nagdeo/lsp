#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){

  int fd=0;

  if(argc!=2){
    printf("Error: Insufficient Argument");
    return -1;
  }

   fd=open(argv[1],O_RDONLY);
  
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   printf("File gets successfully opened with fd : %d\n",fd);
   close(fd);
  printf("Inside main\n");
  return 0;
}
