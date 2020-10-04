#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//This is best way of calling fork system call
int main() 
{
 
    printf("Hello\n");
   
   if(fork()==0) //child process is running
   { 
      printf("A\n");
   }
   else // parent process is running
   {
     printf("B\n");
   }

   exit(0);
}

/*
output:

simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_cls_pogram$ gcc program_4.c -o myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ ./myexe
Hello
B
A

*/
