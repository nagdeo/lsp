#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include<strings.h>

int main(int argc, char *argv[]){

    int fd=0,fd1=0;
    int size=0,size1=0;
    char arr[11],arr1[11];
    int ret=0,ret1=0;

    if(argc!=3){
      printf("Invalid no. of arguments!");
    }
    fd=open(argv[1],O_RDONLY);
   
    if(fd<0){
      printf("Error while opening the file! :(");
       return -1;
    } 
 
     printf(" file 1! %d",fd);
     fd1=open(argv[2],O_RDONLY);
     if(fd1<0){
       printf("Error while opening the file! :(");
       return -1;
     }
     printf(" file 2! %d",fd1);

     size=lseek(fd,0,SEEK_END);
     size1=lseek(fd1,0,SEEK_END);
     if(size==size1){
       
         while(size>0){
             
          ret=read(fd,arr,10);
          ret1=read(fd1,arr1,10);
              write(1,arr,10);
               write(1,arr1,10);
                
            size-=10;
             if(strcasecmp(arr, arr1)==0){
                 printf("File contents are not same");
             }
         }
     }else{
         printf("File contents are not same");
     }
     
     if(size<=0){
       printf("File contents are same");
     }
  
    
   
    return 0;
}
