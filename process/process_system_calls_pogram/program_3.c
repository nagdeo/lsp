#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//This is worst way of calling fork system call
int main() 
{
   printf("Hello\n");
   fork();
   printf("World\n");

   

   exit(0);
}



/*
output:

simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ gcc program_3.c -o myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ ./myexe
Hello
World
World   //copy of text data and stack gets created when fork is called
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ 
*/
