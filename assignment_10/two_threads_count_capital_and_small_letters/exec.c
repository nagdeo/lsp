#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

int counter; //value is 0 (as global)
pthread_mutex_t lock;

//callback methhods of thread
void *countCapAndSmall(void *p)           //child thread
{
 
   int fd=0,ret=0;
    char ch ;
   int upper=0,lower=0;
   fd=open("demo.txt",O_RDONLY);
   char arr[11]={'\0'};
   if(fd==-1){
    printf("Unable to open file");
    return;
   }
   
   
    printf("\n");
   counter++;
   pthread_mutex_lock(&lock);
   if(counter==1)
   {
       while((ret=read(fd,arr,10))!=0){
           for(int i = 0; i < ret; i++) 
           { 
              ch = arr[i]; 
              if (ch >= 'A' && ch <= 'Z') 
                upper++; 
           
           }
        }
      
     printf("Thread %d is running and having capital letters : %d\n",counter,upper);
    } else if(counter ==2)
    {
       while((ret=read(fd,arr,10))!=0){
         for(int i = 0; i < ret; i++) 
          { 
             ch = arr[i]; 
             if (ch >= 'a' && ch <= 'z') 
                 lower++; 
           
          }
       }
      
       printf("Thread %d is running and having small letters : %d\n",counter,lower);
    }
   
 
  
  
  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);     //terminating thread
}
int main() 
{
    pthread_t thread1;
    pthread_t thread2;
   
    int ret =0,no=11;
  
   printf("Inside main thread\n");
    if(pthread_mutex_init(&lock,NULL)!=0) //get the lock from os
   {
      printf("Unable to get Lock");
      return -1;
   }
   ret=pthread_create(&thread1,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      countCapAndSmall,       //address of callback function
                      NULL      //parameters of callback function
                      );

   if(ret!=0){
      printf("unable to create thread 1\n");
   }
    ret=pthread_create(&thread2,   //address of pthread_t pointer
                      NULL,      //attributes of thread
                      countCapAndSmall,       //address of callback function
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


