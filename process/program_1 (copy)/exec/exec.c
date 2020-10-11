#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   

   if(fork()==0) //child process is running
   { 
       printf("child process is running");
      execl("./Demoexe",NULL,NULL); //New process executes
     
   }
   else // parent process is running
   {
     printf("Parent process is running with PID: %d\n",getpid());
      printf("Terminating parent process\n");
   }

   exit(0);
}


