#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int i=10;     //part of data section
int main() 
{
    int *p=NULL;
    p=(int *)malloc(4); 
    *p =10;  
   if(fork()==0) 
   { 
     ++(*p);

      printf("%d\n",*p);
   }
   else // parent process is running
   {
     ++(*p);
      printf("%d\n",*p);
   }

   exit(0);
}

/*
output:
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ gcc program_8.c -o myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram$ ./myexe
11
11


here i is global variable but text data and stack section(separate copy) is different so output is 11 11


*/
