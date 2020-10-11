#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
  printf("Inside new process with pid : %d\n",getpid());
printf("parent pid of child at start is  : %d\n",getppid());
  sleep(20);
  printf("End of child process\n");
printf("parent pid of child at end is  : %d\n",getppid());
 
  return 0;  
}


