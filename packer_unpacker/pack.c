/*
   Application which is used to combine all the regular files from the directory into one regular file  
*/
 
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
// myexe Directoryname Filename
// myexe argv[1] argv[2]
// argv[1] name of directory that we want to open
// argv[2] name of file that contain data of all regular files.


struct FileInfo{
  char fname[256];
  int Fsize;
};
int main(int argc,char *argv[]){

  DIR *dp=NULL;
  struct dirent *dip=NULL;
  struct stat sobj;
  int ret=0,fddes=0,fdsrc=0;
  char name[300]={'\0'};
  char buff[1024];
  struct FileInfo fobj;
  if(argc!=3){
    printf("Error: Insufficient Argument");
    printf("Usage: Directory_name file_name");
    printf("Directory_name : Name of the directory which contains the file name that we want to open");
    printf("file_name : Name of file which contains data of all files");
    return -1;
  }

   dp=opendir(argv[1]);
  
   if(dp==NULL){
    printf("Unable to open Directory : %s ",argv[1]);
    closedir(dp);
    return -1;
   }
   
   fddes=creat(argv[2],0777);
   if(fddes==-1){
      printf("Unable to create file %s ",argv[2]);
   }
   printf("Names of files are:\n");
   while((dip=readdir(dp))!=NULL){
     //printf("%s\n",dip->d_name);
     // sprintf() function is used to copy data in string.
      sprintf(name,"%s/%s",argv[1],dip->d_name); //relative path
      stat(name,&sobj);
      if(S_ISREG(sobj.st_mode)){
         // Fill the structure which contains file info
         strcpy(fobj.fname,dip->d_name);
         fobj.Fsize=sobj.st_size;

         //write the fileinfo structure into the file
         write(fddes,&fobj,sizeof(fobj));

         memset(&fobj,0,sizeof(fobj));  //zerout the memory

         fdsrc=open(name,O_RDONLY);
         // copy contents of all files from dir
         while((ret=read(fdsrc,buff,sizeof(buff)))!=0){
            write(fddes,buff,ret);
         }
         memset(buff,0,sizeof(buff));
         close(fdsrc);
        // printf("%s : %ld\n",dip->d_name,sobj.st_size);
      }
     //ret=stat(dip->d_name,&sobj);  //here name of file is not taking properly, so we have to give proper path.
     //printf("%d\n",ret);
     //printf("%ld\n",sobj.st_size);
   }

   closedir(dp);
  
   return 0;
}
