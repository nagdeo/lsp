#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int i=10;     //part of data section
int main() 
{
 
   
   int i=10;  //part of stack section
   if(fork()==0) //child process is running
   { 
     ++i;
      printf("%d\n",i);
   }
   else // parent process is running
   {
     ++i;
      printf("%d\n",i);
   }

   exit(0);
}

/*
output:
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ gcc program_7.c -o myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ ./myexe
11
11

here i is global variable but text data and stack section(separate copy) is different so output is 11 11


*/
