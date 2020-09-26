#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

void Cp_command(char *src,char *dest){
   int fdsrc=0,fddes=0,ret=0;
   char buff[1024]={'\0'};

   fdsrc=open(src,O_RDONLY);
  
   if(fdsrc==-1){
    printf("Unable to open file");
    return;
   }
   fddes=creat(dest,0777);
   if(fddes==-1){
    printf("Unable to create file");
    return;
   }
   while(ret=read(fdsrc,buff,sizeof(buff))!=0){
      write(fddes,buff,ret);
   }
   close(fdsrc);
   close(fddes);
  printf("Copy successfull\n");
}
int main(int argc,char *argv[]){

  

  if(argc!=3){
    printf("Error: Insufficient Argument\n");
    printf("Usage: cp source.txt destination.txt");
    return -1;
  }
   Cp_command(argv[1],argv[2]);
  
  return 0;
}

