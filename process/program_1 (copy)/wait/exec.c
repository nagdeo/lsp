#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//parent wait till child terminate.
//if we use sleep and if child process require more time than we give timing in sleep 
//then parent kills first so always if parent wait till child terminate use wait systemm call
//

int main() 
{
   
   int pid=0,status=0;
   if(fork()==0) //child process is running
   { 
       printf("child process is running");
      execl("./Demoexe",NULL,NULL); //New process executes
     
   }
   else // parent process is running
   {
     printf("Parent process is running with PID: %d\n",getpid());
     pid=wait(&status);
     //
     //
     printf("Terminated child pid is %d\n ",pid);
     printf("exit status of child is %d\n ",status);
      printf("Terminating parent process\n");
   }

   exit(0);
}


