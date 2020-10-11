#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   
   int ret=0;
   
   ret=nice(0);
   printf("Default priority is : %d\n",ret);

   ret=nice(10);
   printf("Changed priority is : %d\n",ret);

  ret=nice(-7);
   printf("changed priority is : %d\n",ret);
 
   ret=nice(-15);
   printf("changed priority is : %d\n",ret);
   exit(0);
}

/*
  output

  simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/nice$ gcc exec.c -o myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/nice$ ./myexe
Default priority is : 0
Changed priority is : 10
changed priority is : -1
changed priority is : -1
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/nice$ sudo ./myexe
Default priority is : 0
Changed priority is : 10
changed priority is : 3
changed priority is : -12
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/nice$ 


sudo ./myexe why??

value not goes down below -1 so only super user can increase it so run it using sudo

*/

