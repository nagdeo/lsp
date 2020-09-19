#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>

#include <sys/stat.h>

#include <dirent.h>
int main(int argc, char *argv[]){

    DIR* dir;
    struct dirent *dirEntry;
    struct stat inode;
     char name[1000];
     int fd=0,size=0;
    dir = opendir(argv[1]);
  
    if (dir == 0) {
     printf("Error: Unable to open Directory");
      return -1;
    }
  
   printf("Directory Openend :\n");
   printf("File        size\n");

   while ((dirEntry=readdir(dir)) != 0) {
      printf("%s           ", dirEntry->d_name);
       stat(dirEntry->d_name, &inode);
       // printf("%ld bytes\n", inode.st_size);
       dirEntry->d_name=dirEntry->d_name;
       fd=open(dirEntry->d_name,O_RDONLY);
 printf("%d",fd);
       size=lseek(fd, 0, SEEK_END);
       printf("%d",size);
       if(size==-1){
          unlink(dirEntry->d_name);
        }
      size=0;
       fd=0;
   }

   
  return 0;
}
