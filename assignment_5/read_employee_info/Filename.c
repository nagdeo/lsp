#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[]){

   int fd=0,fmode=0;
   char filename[50];
   char arr[11];
   int ret=0;
  
   fd=open(argv[1],O_RDONLY);
  
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   printf("File gets successfully opened with fd : %d\n",fd);

    printf("Employee Info is: ");
    printf("\n");
   while((ret=read(fd,arr,10))!=0){
     write(1,arr,ret);
   }
   close(fd);
  return 0;
}
