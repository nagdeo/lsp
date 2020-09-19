#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

   int fd=0;
   printf("Enter File name:\n");
   char filename[50]; 
   char arr[20];
   scanf("%[^\n]%*c", filename);

   fd=open(filename,O_RDONLY);
  
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   printf("File gets successfully opened with fd : %d\n",fd);
   read(fd,arr,5);
   printf("Those bytes are as follows: %s\n", arr); 
   close(fd);
  return 0;
}
