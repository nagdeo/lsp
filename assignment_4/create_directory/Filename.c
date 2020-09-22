#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

    int dir=0;

    if(argc!=2){
      printf("Invalid no. of arguments!");
    }
    dir=mkdir(argv[1],0777);
   
    if(dir<0){
      printf("Error while creating the directory! :(");
       return -1;
    } 
  
    printf("Directory created successfully! :)");
   
    return 0;
}
