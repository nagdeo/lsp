#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){

   int fd=0;
   char arr[20];
   
   fd=open(argv[1],O_RDONLY);
  
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   printf("File gets successfully opened with fd : %d\n",fd);
   read(fd,arr,atoi(argv[2]));
   printf("Those bytes are as follows: \n");
   write(1,arr,atoi(argv[2])); 
   close(fd);
  return 0;
}
