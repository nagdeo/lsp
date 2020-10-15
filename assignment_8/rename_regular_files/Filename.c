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
    char name[270] = {'\0'};
   char name1[270] = {'\0'};
   char rep[270]={'\0'};
    int no=1;
    dir = opendir(argv[1]);
  
    if (dir == 0) {
     printf("Error: Unable to open Directory");
      return -1;
    }
  
   
   while ((dirEntry=readdir(dir)) != 0) {
    //  printf("%s           ", dirEntry->d_name);
         sprintf(name,"%s/%s", argv[1],dirEntry->d_name);
	 stat(name,&filestat);
       snprintf(name1, 12, "%d.txt", no); 
       sprintf(rep,"%s/%s", argv[1],name1);
      //printf("%s",name1);
      if(S_ISREG(filestat.st_mode)){
           rename(name,rep);     
            no++;    
      }
     
      
   }

   
  return 0;
}
