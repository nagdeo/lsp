#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() 
{
  
  int msgid=msgget(ftok('.',11),0666);

  struct demo{
    int type;
    char data[512];
  }obj3;

  long int msgtype=getpid();

  msgrcv(msgid,(void*)&obj3,msgtype,512,IPC_NOWAIT);
  printf("Data from the parent is %s \n",obj3.data);
 
  return 0;  
}
