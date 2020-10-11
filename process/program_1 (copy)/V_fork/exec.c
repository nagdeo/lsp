#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   
   int no=10;
   if(fork()==0) //child process is running
   { 
       printf("child process is running : %d\n",no);
     
   }
   else // parent process is running
   {
     printf("Parent process is running : %d\n",no);
    
   }

   exit(0);
}


