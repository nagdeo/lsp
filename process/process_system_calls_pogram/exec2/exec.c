#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/*exec system call is used to replace text,data and stack of existing child process with text,data and stack of new process*/
int main() 
{
   

   if(fork()==0) //child process is running
   { 
      execl("./Demoexe","Python","Golang",NULL); //New process executes
     
   }
   else // parent process is running
   {
     printf("Parent process is running with PID: %d\n",getpid());
 
   }

   exit(0);
}

/*
output:
     in case of running process first arugument is name of file but in case of exec arguments value starts from argv[0] and noy name of file

     that is
     execl("./Demoexe","Python","Golang",NULL);
          (path,argv[0],argv[1],argv[2])

     ./Demoexe python golang
     argv[0] argv[1] argv[2]



how to execute:
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram/exec2$ gcc Demo.c -o Demoexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram/exec2$ ./Demoexe Python Golang
Inside new process with pid : 7382
First Argument : ./Demoexe
Second Argument : Python
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram/exec2$ gcc exec.c -o myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram/exec2$ ./myexe
Parent process is running with PID: 7388
Inside new process with pid : 7389
First Argument : Python
Second Argument : Golang
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/process_system_calls_pogram/exec2$ 


Note: do not write any statement before and after exec() as it overwrites the text section 
we can't predict whether line 1 gets overwriiten or not but line 3 gets overwritten

line 1   printf("before exec");
line 2   exec()
line 3   printf("after exec");

*/
