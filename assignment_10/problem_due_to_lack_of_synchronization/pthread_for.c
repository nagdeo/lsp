#include<stdio.h>
#include<pthread.h>


int counter; //value is 0 (as global)


//callback methhods of thread
void *ThreadProc(void *p)           //child thread
{
 
  unsigned long i=0;
  counter++;
  
  printf("Task %d started successfully\n",counter);

  for(i=0;i<0xffffffff;i++);

  printf("Task %d finished successfully\n",counter);

 
  pthread_exit(NULL);     //terminating thread
}
int main() 
{
    pthread_t thread1;
    pthread_t thread2;
   
    int ret =0,no=11;
  
   printf("Inside main thread\n");
   
   ret=pthread_create(&thread1,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      ThreadProc,       //address of callback function
                      NULL      //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 1\n");
   }
    ret=pthread_create(&thread2,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      ThreadProc,       //address of callback function
                      NULL       //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 2\n");
   }
    
 
   pthread_join(thread1  //pthread_t pointer
                , NULL); //status of thread
    pthread_join(thread2  //pthread_t pointer
                , NULL); //status of thread

   printf("Terminating main thread\n"); // this method tells parent to stop until child terminate
   return 0;
}


/*

  output:



Inside main thread
Task 1 started successfully
Task 2 started successfully
Task 2 finished successfully
Task 2 finished successfully
Terminating main thread


*/

