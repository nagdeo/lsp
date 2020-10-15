#include<sys/resource.h>
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
int which = PRIO_PROCESS;
id_t pid;
int ret;


pid = getpid();
ret = getpriority(which, pid);
printf("%d",ret);
  return 0;

}
