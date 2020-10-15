#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() 
{
    int fd=0,ret=0;
    char ch ;
   int upper=0,lower=0;
   fd=open("demo.txt",O_RDONLY);
   char arr[11]={'\0'};
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   
   
    printf("\n");
   while((ret=read(fd,arr,10))!=0){
     for(int i = 0; i < ret; i++) 
        { 
            ch = arr[i]; 
            if (ch >= 'A' && ch <= 'Z') 
                upper++; 
           
        }
   }
  
   
  printf("Child process 1 is running and having capital letters : %d\n",upper);
  //fd=open("count.txt",O_RDWR);
  //write(fd,"Capital Letters: ",17);
  //write(fd,upper,sizeof(upper));
  close(fd);
  return 0;  
}


