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
// myexe argv[1]
// argv[1] name of file that contain merged data 

struct FileInfo{
  char fname[256];
  int Fsize;
};
int main(int argc,char *argv[]){

  DIR *dp=NULL;
 
  int ret=0,fddes=0,fdsrc=0,dir;
  char name[300]={'\0'};
  char buff[1024];
  char *buffer;
  struct FileInfo fobj;
  if(argc!=3){
    printf("Error: Insufficient Argument");
    printf("Usage: file_name directory_to_create");
    printf("Directory_name : Name of the directory which contains the file name that we want to open");
    printf("file_name : Name of file which contains data of all files");
    return -1;
  }

   fdsrc=open(argv[1],O_RDONLY);
   if(fdsrc==-1){
      printf("Unable to open file\n");
      return -1;
   }
   dir=mkdir(argv[2],0777);
    if(dir<0){
      printf("Error while creating the directory! :( : %s",argv[2]);
       return -1;
    } 
   while((ret=read(fdsrc,&fobj,sizeof(fobj)))!=0){
      printf("File name : %s Size: %d\n",fobj.fname,fobj.Fsize);
       sprintf(name,"%s/%s", argv[2],fobj.fname);
      fddes=creat(name,0777);
      if(fddes==-1){
        printf("Unable to create file\n");
        return -1;
      }
      //dynamic memory for data to read
      buffer=(char*)malloc(fobj.Fsize);
      //read the data from merged file
      read(fdsrc,buffer,fobj.Fsize);
     // write the data into newly created file
      write(fddes,buffer,fobj.Fsize);
      // free the memory
      free(buffer);
      close(fddes);
     // lseek(fdsrc,fobj.Fsize,SEEK_CUR);
   }
   close(fdsrc);
   //unlink(argv[1]);  //if u want to delete the hello.txt 
   return 0;
}
