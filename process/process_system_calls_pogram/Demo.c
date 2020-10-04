#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{

    
  
    printf("Process is running...\n");
    printf("Pid of parent process(Terminal) is %d \n",getppid());
    printf("Pid of current process is %d \n",getpid());

   for(;;){} //Infinite loop
   exit(0);
}
