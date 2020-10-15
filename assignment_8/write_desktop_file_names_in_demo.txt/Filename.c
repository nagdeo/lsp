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
    struct stat filestat;
    int fd=0,fd1=0;
    dir = opendir("/home/simran/Desktop");
  
    if (dir == 0) {
     printf("Error: Unable to open Directory");
      return -1;
    }
   fd=creat("Demo.txt",0777);
   if(fd==-1)
   {
      printf("Unable to create demo.txt!");
   }
   fd1=open("Demo.txt",O_RDWR);
   while ((dirEntry=readdir(dir)) != 0) {
    //  printf("%s           ", dirEntry->d_name);
       write(fd1,dirEntry->d_name,sizeof(dirEntry->d_name));
   }

   
  return 0;
}
