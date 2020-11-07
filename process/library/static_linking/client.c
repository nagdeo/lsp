#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include"library.h"


int main() 
{

    int value1=10,value2=11,ret=0;
    ret=add(value1,value2);
    printf("Addition is : %d \n",ret);


    ret=sub(value1,value2);
    printf("Substraction is : %d \n",ret);

    return 0;
}






/*

simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/static_linking$ gcc -c -fpic library.c     //to create .o
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/static_linking$ ls
client.c  library.c  library.h  library.o
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/static_linking$ ar rcs library.a library.o    //to create archieve file -->library.a    //rcs->replace(if file(library.a) found replace) create(if not found create) sort
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/static_linking$ gcc client.c -o myexe
/tmp/ccpcSfah.o: In function `main':
client.c:(.text+0x28): undefined reference to `add'
client.c:(.text+0x50): undefined reference to `sub'
collect2: error: ld returned 1 exit status
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/static_linking$ cc client.c -o myexe library.a
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/static_linking$ gcc client.c -o myexe library.a
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/static_linking$ ls
client.c  library.a  library.c  library.h  library.o  myexe
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/static_linking$ ./myexe
Addition is : 21 
Substraction is : -1 
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/static_linking$ 


*/

