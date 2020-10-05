#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() 
{
    int c1=0;
    int c2=0;
   if((c1=fork())==0) 
   { 
      printf("Hello I'm Child 1\n");
      printf("child Terminated 1\n");
   }else if((c2=fork())==0) 
   { 
      printf("Hello I'm Child 2\n");
      printf("child Terminated 2\n");
   }
   else // parent process is running
   {
     printf("Hello I'm Parent\n");
      wait(NULL); 
      
     printf("Parent Terminated\n");
   }
   
  
   
   exit(0);
}

/*



*/
