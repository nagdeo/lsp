#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dlfcn.h>


int main() 
{
    void *lib=NULL;
    //int add(int no1,int no2) 
    int (*fptr)(int,int);
    int (*fptr1)(int,int); 
    int value1=10,value2=11,ret=0;
    printf("Loading the library dynamically\n");

    lib=dlopen("./library.so",RTLD_LAZY);      //load library in memory (ram) and put in potential gap
                                               // rtld_lazy : run time load lazily
    if(lib == NULL) {
       printf("Unable to link the library\n");
       return -1;
    }
    printf("Libray Loaded Successfully\n");
    printf("Fetching the address of add function\n");

    fptr= dlsym(lib,"add");  // to get address of function
    if(fptr == NULL) {
       printf("Unable to get address\n");
       return -1;
    }
    printf("Address of function fetched successfully\n");
    ret = fptr(value1,value2);
    printf("Addition is %d\n",ret);

    //sub

    printf("Fetching the address of add function\n");

    fptr1= dlsym(lib,"sub");
    if(fptr1 == NULL) {
       printf("Unable to get address\n");
       return -1;
    }
    printf("Address of function fetched successfully\n");
    ret = fptr1(value1,value2);
    printf("Substraction is is %d\n",ret);

    dlclose(lib);      //decrement the reference count  (ref count: how many process are using that library)
    printf("Dynamic library unlinked\n");

    for(;;);
    return 0;
}






/*
  ldl(link ar dynamic linking)->  says linking at run time



simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ gcc -c -fpic library.c     //to create .o
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ gcc -shared -o library.so library.o
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ ls
client.c  library.c  library.o  library.so
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ gcc client.c
/tmp/ccP49VPH.o: In function `main':
client.c:(.text+0x29): undefined reference to `dlopen'
collect2: error: ld returned 1 exit status
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ gcc client.c -o myexe  -ldl
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ ./myexe
Loading the library dynamically
Libray Loaded Successfully
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ 


simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ gcc client.c -o myexe  -ldl
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ ./myexe
Loading the library dynamically
Libray Loaded Successfully
Fetching the address of add function
Address of function fetched successfully
Addition is 21
Dynamic library unlinked
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ 




simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ gcc client.c -o myexe  -ldl
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ ./myexe
Loading the library dynamically
Libray Loaded Successfully
Fetching the address of add function
Address of function fetched successfully
Addition is 21
Fetching the address of add function
Address of function fetched successfully
Substraction is is -1
Dynamic library unlinked






//to show dynamic linking(both process sharing same library)
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ gcc client.c -o myexe1  -ldl
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ gcc client.c -o myexe2  -ldl
simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ 
  ------------------>1st terminal
     simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ ./myexe2
Loading the library dynamically
Libray Loaded Successfully
Fetching the address of add function
Address of function fetched successfully
Addition is 21
Fetching the address of add function
Address of function fetched successfully
Substraction is is -1
Dynamic library unlinked
 -------------------->2nd terminal
 simran@simran-Lenovo-IdeaPad-S145-15IWL:~/Desktop/lsp/process/library/dynamic_linking$ ./myexe1
Loading the library dynamically
Libray Loaded Successfully
Fetching the address of add function
Address of function fetched successfully
Addition is 21
Fetching the address of add function
Address of function fetched successfully
Substraction is is -1
Dynamic library unlinked




*/

