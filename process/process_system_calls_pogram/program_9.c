#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() 
{
    int fd=0;
    fd=open("Demo.txt",O_WRONLY); //file opened by parent process
    
   if(fork()==0) 
   { 
    write(fd,"child",5);
   }
   else // parent process is running
   {
     write(fd,"parent",6);
   }

   exit(0);
}

/*



*/
