#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//callback methhods of thread
void * Fun(void *p)           //child thread
{
  printf("Inside thread with fun %d\n",p);
  for(int i=0;i<p;i++)
  {
     printf("Fun:%d\n",i);
  }
  pthread_exit(NULL);     //terminating thread
}
void * Gun(void *p)           //child thread
{
  printf("Inside thread with gun: %d\n",p);
  for(int i=0;i<p;i++)
  {
     printf("Gun:%d\n",i);
  }
  pthread_exit(NULL);
}
int main() 
{
   pthread_t thread1;
    pthread_t thread2;
   int ret =0;
   int no1=1000,no2=2000;
   printf("Inside main thread\n");
   ret=pthread_create(&thread1,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      Fun,       //address of callback function
                      (void *)no1       //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 1\n");
   }
    ret=pthread_create(&thread2,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      Gun,       //address of callback function
                      (void *)no2       //parameters of callback function
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

   pthread - immediately create thread and immediatelty runs
*/
/*

how to run

simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ gcc pthread_for.c -o myexe -lpthread
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ ./myexe > output.txt                     //copy output in output.txt
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/program_1 (copy)/p_thread$ 





*/


