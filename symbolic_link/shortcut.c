#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){

    int fd=0,ret=0;
    char buffer[30];
    char path[60];
    fd=symlink("data.txt","myshortcut.txt");
 
   
    if(fd==-1){
       printf("unable to create symbolic link");
         return -1;
     }
      printf("Link Created \n");
    fd=open("myshortcut.txt",O_RDONLY);
    if(fd==-1){
       printf("unable to open file");
         return -1;
     }
    ret=read(fd,buffer,30);
    printf("Data from the symbolic link is : \n");
    write(1,buffer,ret);
    
    ret=readlink("myshortcut.txt",path,60);
  
    printf("Data from the symbolic link through readlink is : \n");
    write(1,path,ret);

    close(fd);
  return 0;
}

