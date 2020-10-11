#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   
   int no=10;
   
   printf("child process is running : %d\n",no);
    printf("child process is running with pid : %d\n",getpid());
   
   exit(0);
}


