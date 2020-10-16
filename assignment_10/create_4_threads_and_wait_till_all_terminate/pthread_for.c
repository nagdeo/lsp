#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//callback methhods of thread
void * Fun()           //child thread
{
  printf("Inside thread 1 with fun\n");
  pthread_exit(NULL);     //terminating thread
}
void * Gun()           //child thread
{
  printf("Inside thread 2 with gun:\n");
 
  pthread_exit(NULL);
}
void * Sun()           //child thread
{
  printf("Inside thread 3 with Sun\n");
  pthread_exit(NULL);     //terminating thread
}
void * Mun()           //child thread
{
  printf("Inside thread 4 with Mun:\n");
 
  pthread_exit(NULL);
}
int main() 
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    int ret =0;
  
   printf("Inside main thread\n");
   ret=pthread_create(&thread1,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      Fun,       //address of callback function
                      NULL      //parameters of callback function
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
    ret=pthread_create(&thread3,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      Sun,       //address of callback function
                      NULL       //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 2\n");
   }
    ret=pthread_create(&thread4,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      Mun,       //address of callback function
                      NULL       //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 2\n");
   }
 
   pthread_join(thread1  //pthread_t pointer
                , NULL); //status of thread
    pthread_join(thread2  //pthread_t pointer
                , NULL); //status of thread
    pthread_join(thread3  //pthread_t pointer
                , NULL); //status of thread
    pthread_join(thread4  //pthread_t pointer
                , NULL); //status of thread
   printf("Terminating main thread\n"); // this method tells parent to stop until child terminate
   return 0;
}


