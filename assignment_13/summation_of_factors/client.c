#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dlfcn.h>


int main() 
{
    void *lib=NULL;
    
  
    int (*fptr)(int);
    
    int value1=10,value2=11,ret=0;
    printf("Loading the library dynamically\n");

    lib=dlopen("./library.so",RTLD_LAZY);      //load library in memory (ram) and put in potential gap
                                               // rtld_lazy : run time load lazily
    if(lib == NULL) {
       printf("Unable to link the library\n");
       return -1;
    }
    printf("Libray Loaded Successfully\n");
    printf("Fetching the address of factorSum function\n");

    fptr= dlsym(lib,"factorSum");  // to get address of function
    if(fptr == NULL) {
       printf("Unable to get address\n");
       return -1;
    }
    printf("Address of function fetched successfully\n");
    ret = fptr(12);
     printf("Sum of factors is %d\n",ret);
 
    
    dlclose(lib);      //decrement the reference count  (ref count: how many process are using that library)
    printf("Dynamic library unlinked\n");

    for(;;);
    return 0;
}







