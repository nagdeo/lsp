#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
struct employee  
{ 
    int id; 
    char fname[20]; 
    char lname[20];
    char email[50]; 
};
int main(int argc, char * argv[]){

   int fd=0;
   int ret=0;
  fd=open(argv[1],O_WRONLY|O_APPEND);
  
   struct employee emp;
  
  
   
  
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   printf("File gets successfully opened with fd : %d\n",fd);   
   
    while((ret=read(fd,&emp,sizeof(emp)))!=0){
      printf("Employee Info is \n:Id:%d \n fname: %s \n Lname: %s \n email: %s\n",emp.id,emp.fname,emp.lname,emp.email);

    }
  
   close(fd);
  return 0;
}
