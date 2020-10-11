#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void fun()
{
  int i=0;
  for(i=0;i<10000;i++)
  {

  }
}

void gun()
{
  int i=0;
  for(i=0;i<10000;i++)
  {

  }
}

int main() 
{
   fun();
   gun();
   
   return 0;
}


/*
  serial prog(default)

  parallel prog(multithreading)
*/
