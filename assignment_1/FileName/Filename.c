#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

   int fd=0;
   printf("Enter File name:\n");
   char filename[50]; 
   scanf("%[^\n]%*c", filename);

   fd=open(filename,O_RDONLY);
  
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   printf("File gets successfully opened with fd : %d\n",fd);
   close(fd);
  return 0;
}
