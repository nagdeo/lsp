#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[]) 
{
   
   int pid=0,status=0,ret=0,ret1=0;
   if((ret=fork())==0) //child process is running
   { 
       printf("child process is created\n");
      execl("./myexe",argv[1],NULL); //New process executes
     
   }
   else // parent process is running
   {
      printf("parent  process can wait\n");
     pid=wait(&status);
     printf("Terminating parent process\n");
      
   }
 
   exit(0);
}


/*
   how to execute

   simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/sunday_10_oct$ gcc file.c -o myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/sunday_10_oct$ gcc process.c -o processexe
process.c: In function ‘main’:
process.c:19:10: warning: implicit declaration of function ‘wait’; did you mean ‘main’? [-Wimplicit-function-declaration]
      pid=wait(&status);
          ^~~~
          main
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/sunday_10_oct$ ./processexe data.txt
parent  process can wait
child process is created
child process opens the file : data.txtData from file is
//parent wait till child terminate.
//if we use sleep and if child process require more time than we give timing in sleep 
//then parent kills first so always if parent wait till child terminate use wait systemm call
//


End of the process
Terminating parent process

*/
