#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){

   int fd=0,fmode=0;
   char filename[50];
   char mode[20];
   printf("Enter File name:\n");
   scanf("%[^\n]%*c", filename);
   printf("Enter File mode:1) read 2) write 3) readWrite\n");
   scanf("%[^\n]%*c", mode);
   if(strcmp(mode,"read")){
      fmode=O_RDONLY;
   } else if(strcmp(mode,"write")){
      fmode=O_WRONLY;
   } else if(strcmp(mode,"readWrite")){
      fmode=O_RDWR;
   }
   printf("file mode value is: %d\n",fmode);

   fd=open(filename,fmode);
  
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   printf("File gets successfully opened with fd : %d\n",fd);
   close(fd);
  return 0;
}
