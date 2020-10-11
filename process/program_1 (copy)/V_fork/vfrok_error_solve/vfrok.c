#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   
   int no=10,ret=0;
    ret=vfork();
   if(ret==0) //child process is running
   { 
       execl("./myexe",NULL,NULL);
     
   }
   else // parent process is running
   {

     printf("parent pid is : %d\n",getppid());
     printf("child pid is : %d\n",ret);
     printf("Parent process is running : %d\n",no);
    
   }

   return 0;
}


