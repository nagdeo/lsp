#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

   int fd;
    int size=0;
    char *c = (char *) calloc(100, sizeof(char)); 
   printf("Enter File name:\n");
   char filename[50]; 
   
   scanf("%[^\n]%*c", filename);

   fd=open(filename,O_RDONLY);
  
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   printf("File gets successfully opened with fd : %d\n",fd);
   
    size=lseek(fd, 0, SEEK_END);
    
    if(size!=-1)
        printf("File size is: %d\n",size);
    else
        printf("There is some ERROR.\n");
  
    read(fd,c,size);
   printf("Those bytes are as follows: %s\n", c); 
   close(fd);
  return 0;
}
