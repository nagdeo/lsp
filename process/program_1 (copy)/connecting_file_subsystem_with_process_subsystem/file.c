#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) 
{
   
   int ret=0,fd=0;
   char buffer[1024]={'\0'};
   
   printf("child process opens the file : %s",argv[0]); //argv[0] because execl contains arguments from index 0
   if(argv[1]==NULL)  //if opening from process
   {
     fd=open(argv[0],O_RDONLY); 
   }
   else    // if file.c is running without process
   {
      fd=open(argv[1],O_RDONLY); 
   }
   

   if(fd==-1) //child process is running
   { 
       printf("Unable to open file\n");
       return -1;
   }
   printf("Data from file is\n");
   while((ret=read(fd,buffer,sizeof(buffer)))!=0){
     write(1,buffer,ret);
   }

    printf("End of the process\n");
   exit(0);
}


