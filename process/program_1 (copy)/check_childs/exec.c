#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   

   int pid=0,status=0;
   pid=wait(&status);
   printf("%d",pid);
   if(pid==-1){
     printf("No childs");
   }

   exit(0);
}


