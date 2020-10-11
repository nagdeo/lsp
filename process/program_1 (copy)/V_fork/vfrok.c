#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   
   int no=10,ret=0;
    ret=vfork();
   if(ret==0) //child process is running
   { 
       printf("child process is running : %d\n",no);
     
   }
   else // parent process is running
   {
     printf("Parent process is running : %d\n",no);
    
   }

   return 0;
}


//core dumped is screenshot of error
/*

output


  simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/V_fork$ gcc vfrok.c -o vexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/V_fork$ ./vexe
child process is running : 10
Parent process is running : 1912238570
Segmentation fault (core dumped)  //error because not creating text data and stack of child so at if conditionerror

*/



/*

  int main() 
{
   
   int no=10,ret=0;
    ret=vfork();
   if(ret==0) //child process is running
   { 
       printf("child process is running : %d\n",no);
     
   }
   else // parent process is running
   {
     printf("Parent process is running : %d\n",no);
    
   }

   exit(0);
}




output


  simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/V_fork$ gcc vfrok.c -o vexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/V_fork$ ./vexe
child process is running : 10
Parent process is running : 10


*/
