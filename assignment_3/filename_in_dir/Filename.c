#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include<string.h>
#include <sys/stat.h>

#include <dirent.h>
int main(int argc, char *argv[]){

    DIR* dir;
    int c=0;
    struct dirent *dirEntry;
    dir = opendir(argv[1]);
  
    if (dir == 0) {
     printf("Error: Unable to open Directory");
      return -1;
    }
  
   printf("Directory Openend :\n");
   while ((dirEntry=readdir(dir)) != 0) {
      printf("%s",dirEntry->d_name);
      if(strcmp(argv[2],dirEntry->d_name)){
        c=1;
         printf("File is present");
      }  
   }
   if(c==0){
     printf("File is not present");
   } 
  return 0;
}
