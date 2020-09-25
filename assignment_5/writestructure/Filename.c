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
   //emp.fname=NULL;emp.lname=NULL;emp.email=NULL;
   //emp.id=(int*)malloc(sizeof(int)*atoi(argv[2]));
   //emp.fname=(char*)malloc(sizeof(char)*atoi(argv[3]));
   //emp.lname=(char*)malloc(sizeof(char)*atoi(argv[4]));
   //emp.email=(char*)malloc(sizeof(char)*atoi(argv[5]));
   emp.id = atoi(argv[2]);
   strcpy(emp.fname,argv[3]); 
   strcpy(emp.lname,argv[4]); 
   strcpy(emp.email,argv[5]); 
  
   
  
   if(fd==-1){
    printf("Unable to open file");
    return -1;
   }
   printf("File gets successfully opened with fd : %d\n",fd);   
   
   write(fd,&emp,sizeof(struct employee));
  
   close(fd);
  return 0;
}
