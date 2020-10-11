#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   
   int pid=0,status=0,ret=0,ret1=0;
   if((ret=fork())==0) //child process is running
   { 
       printf("child process 1 is created by parent having pid : %d\n",getppid());
      execl("./Demoexe1",NULL,NULL); //New process executes
     
   }
   else // parent process is running
   {
       if((ret1=fork())==0) //child process is running
       { 
         printf("child process 2 is created by parent having pid: %d\n",getppid());
         execl("./Demoexe2",NULL,NULL); //New process executes
     
       }
      while((pid=wait(&status))>0){
         printf("%d child gets terminated\n", pid);
      }
      
   }
   printf("End of parent process\n");
   exit(0);
}


