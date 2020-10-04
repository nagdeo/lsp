#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   int ret=0;
   ret=fork(); //The process which calls fork, then the exact copy of that process is created.
               // fork returns 2 return values

   if(ret==0) //child process is running
   { 
      printf("Child process is running with PID: %d\n",getpid());
      printf("Parent ofChild process: %d\n",getppid());
      printf("Child says:value of ret  is : %d\n",ret);
   }
   else // parent process is running
   {
     printf("Parent process is running with PID: %d\n",getpid());
     printf("Parent of parent process: %d\n",getppid());
     printf("Parent says:value of ret  is : %d\n",ret);
   }

   exit(0);
}

/*
output:

Parent process is running with PID: 4035
Parent of parent process: 3858
Parent says:value of ret  is : 4036
Child process is running with PID: 4036
Parent ofChild process: 4035
Child says:value of ret  is : 0


if Parent ofChild process: 1
 means parent process is killed so pid of child is 1(process id of init process that is process 1)
*/
