#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//callback methhods of thread
void * Fun(void *p)           //child thread
{
  printf("Inside thread with fun\n");
  pthread_exit(NULL);     //terminating thread
}
void * Gun(void *p)           //child thread
{
  printf("Inside thread with gun\n");
  pthread_exit(NULL);
}
int main() 
{
   pthread_t thread1;
    pthread_t thread2;
   int ret =0;
   printf("Inside main thread\n");
   ret=pthread_create(&thread1,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      Fun,       //address of callback function
                      NULL       //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 1\n");
   }
    ret=pthread_create(&thread2,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      Gun,       //address of callback function
                      NULL       //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 2\n");
   }
   //sleep(10); or for(;;);
   pthread_join(thread1  //pthread_t pointer
                , NULL); //status of thread
    pthread_join(thread2  //pthread_t pointer
                , NULL); //status of thread
   printf("Terminating main thread\n"); // this method tells parent to stop until child terminate
   return 0;
}

/*
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ gcc pthread.c -o processexe
/tmp/ccDUGACN.o: In function `main':
pthread.c:(.text+0x52): undefined reference to `pthread_create'
collect2: error: ld returned 1 exit status
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ gcc pthread.c -o processexe
/tmp/ccFRPSjS.o: In function `main':
pthread.c:(.text+0x59): undefined reference to `pthread_create'
collect2: error: ld returned 1 exit status
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ gcc pthread.c -o processexe -lpthread
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ clear

simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ gcc pthread.c -o processexe -lpthread
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ 

*/

/*
   simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ ./processexe
Inside main thread
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ ./processexe
Inside main thread
Inside fun with thread
Inside fun with thread

*/
/*

  if we use sleep(10)
  simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ gcc pthread.c -o processexe -lpthread
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ ./processexe
Inside main thread
Inside fun with thread
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ 

   like same scenario parent wait till child execute , in thread we cant use wait so we use sleep but dont use sleep use join
*/



/*
also gun:

simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ gcc pthread.c -o processexe -lpthread
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ ./processexe
Inside main thread
Inside thread with fun
Inside thread with gun
Terminating main thread


*/
