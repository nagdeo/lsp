#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() 
{
    
   if(fork()==0) 
   { 
      printf("Hello I'm Child\n");
      printf("child Terminated\n");
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
