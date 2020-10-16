#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//callback methhods of thread
void * Fun()           //child thread
{
    
  printf("In Fun function thread id = %d\n", pthread_self()); 
  pthread_exit(NULL);     //terminating thread
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
                      NULL    //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 1\n");
   }
   
   pthread_join(thread1  //pthread_t pointer
                , NULL); //status of thread
   
   printf("Terminating main thread\n"); // this method tells parent to stop until child terminate
   return 0;
}


