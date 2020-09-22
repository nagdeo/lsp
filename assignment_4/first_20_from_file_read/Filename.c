#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[]){

    int fd=0,ret=0;
    char arr[11];

    if(argc!=2){
      printf("Invalid no. of arguments!");
      
    }
    fd=open(argv[1],O_RDONLY);
   
    if(fd<0){
      printf("Error while opening the file! :(");
       return -1;
    } 
 
   
     lseek(fd,atoi(argv[2]),SEEK_CUR);
     
     while((ret=read(fd,arr,10))!=0){
       write(1,arr,ret);
     }
  
    
   
    return 0;
}
