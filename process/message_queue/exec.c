#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

#include<sys/msg.h>

struct my_msg_st
{
	long int my_msg_type;
	char some_text[BUFSIZ];
}obj1,obj2,obj3;

int main() 
{
   
   int pid=0,status=0,ret=0,ret1=0,ret2=0,ret3=0;
   
int running = 1;
int msgid;

long int msg_to_receive = 0;
msgid = msgget(ftok('.',11),0666 | IPC_CREAT);
   if((ret=fork())==0) //child process is running
   { 
       printf("child process 1 is created by parent having pid : %d\n",getppid());
       obj1.type=getppid();
       
      execl("./Demoexe1",NULL,NULL); //New process executes
     
   }
  
   if((ret1=fork())==0) //child process is running
       { 
         printf("child process 2 is created by parent having pid: %d\n",getppid());
         execl("./Demoexe2",NULL,NULL); //New process executes
     
    }
       
    if((ret2=fork())==0) //child process is running
         { 
           printf("child process 3 is created by parent having pid: %d\n",getppid());
           execl("./Demoexe3",NULL,NULL); //New process executes
     
    }
          
    if((ret3=fork())==0) //child process is running
              { 
                 printf("child process 4 is created by parent having pid: %d\n",getppid());
                 execl("./Demoexe4",NULL,NULL); //New process executes
     
     }

  
   printf("End of parent process\n");
   exit(0);
}


