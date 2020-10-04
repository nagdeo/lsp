#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void fun()     //part of text section
{
    int i=10;  //part of stack section
    ++i;
    printf("%d\n",i);
 }
//This is best way of calling fork system call
int main() 
{
 
   
   int i=10;  //part of stack section
   if(fork()==0) //child process is running
   { 
    fun();
      
   }
   else // parent process is running
   {
    fun();
   }

   exit(0);
}

/*
output:

simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ gcc program_6.c -o myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ ./myexe
11
11


*/
