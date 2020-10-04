#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//This is best way of calling fork system call
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
here i is local variable ans stack data and stack of parent and child is different so output 11 11
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_cls_pogram$ gcc program_4.c -o myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ ./myexe
Hello
B
A

*/
