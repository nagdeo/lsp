#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() 
{
    
   if(fork()==0) 
   { 
      printf("Hello I'm Process 2\n");
      printf("Process 2 Terminated\n");
   }
   else 
   {
      if(fork()==0) 
      { 
         printf("Hello I'm Process 3\n");
         printf("Process 3 Terminated\n");
      }
      else 
      {
          if(fork()==0) 
         { 
             printf("Hello I'm Process 4\n");
             printf("child 4 Terminated\n");
         }
         else 
         {
           printf("Hello I'm Parent\n");
         }
      }
     
   }

   
   exit(0);
}

/*



*/
