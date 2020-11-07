#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<signal.h>

void SignalHandler(int number){
   printf("signal is received with %d\n",number);
}

int main() 
{

  
    printf("Process is running with pid %d\n",getpid());
    signal(SIGHUP,SignalHandler);

    for(;;);
  return 0;   //Exit status of process
 
}








/*

  simran@simran-Lenovo-IdeaPad-S145-15IWL:~$ kill -l
 1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
 6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
63) SIGRTMAX-1	64) SIGRTMAX	
simran@simran-Lenovo-IdeaPad-S145-15IWL:~$ 
*/

/*
    how to run


    simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/signal$ ./myexe
Process is running with pid 7638                     
signal is received with 1                        //after execting kill command on terminal 2


simran@simran-Lenovo-IdeaPad-S145-15IWL:~$ kill -1 7638
simran@simran-Lenovo-IdeaPad-S145-15IWL:~$



*/
