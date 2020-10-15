#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
   
   int ret=0;
   
  

   ret=nice(-5);
   printf("Changed priority is : %d\n",ret);

   exit(0);
}
