#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc,char *argv[]) 
{
  printf("Inside new process with pid : %d\n",getpid());
  printf("First Argument : %s\n",argv[0]);
  printf("Second Argument : %s\n",argv[1]);
  return 0;  
}


