#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
  
  sleep(5);
  printf("Child process 1 is running with pid : %d \n",getpid());
 
  return 0;  
}


