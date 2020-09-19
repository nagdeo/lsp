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
    dir = opendir(argv[1]);
  
    if (dir == 0) {
     printf("Error: Unable to open Directory");
      return -1;
    }
  
   printf("Directory Openend :\n");
   printf("File        Type\n");

   while ((dirEntry=readdir(dir)) != 0) {
      printf("%s           ", dirEntry->d_name);
       stat(dirEntry->d_name, &inode);
    
     switch (inode.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device ");            break;
    case S_IFCHR:  printf("character device ");        break;
    case S_IFDIR:  printf("directory ");               break;
    case S_IFIFO:  printf("FIFO/pipe ");               break;
    case S_IFLNK:  printf("symlink ");                 break;
    case S_IFREG:  printf("regular file ");            break;
    case S_IFSOCK: printf("socket ");                  break;
    default:       printf("unknown? ");                break;
    }
   printf("%ld bytes\n", inode.st_size);
       
   }

   
  return 0;
}
