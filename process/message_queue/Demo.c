#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int No1=10;  //Initialised Global goes into non BSS data section
int No2;     //Non Initialised Global goes into BSS data section

int main(int argc,char *argv[]) //Command line arguments
{

    int No3=20;                     //local variable goes into stack
    int *p=(int *)malloc(16);       //Dynamic memory goes into heap
  
    printf("Process is running...\n");
    printf("Pid of parent process is %d \n",getppid());
    printf("Pid of current process is %d \n",getpid());

   free(p);
  return 0;   //Exit status of process
 //exit(0);
}
