#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//callback methhods of thread
void * Fun(void *p)           //child thread
{
  printf("Inside thread with parameter from main %d\n",p);
  
  pthread_exit(NULL);     //terminating thread
}

int main() 
{
   pthread_t thread1;
    pthread_t thread2;
   int ret =0;
   int no1=500,no2=500;
   printf("Inside main thread\n");
   ret=pthread_create(&thread1,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      Fun,       //address of callback function
                      (void *)no1       //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 1\n");
   }
    
   pthread_join(thread1  //pthread_t pointer
                , NULL); //status of thread
    
   printf("Terminating main thread\n"); // this method tells parent to stop until child terminate
   return 0;
}



