#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dlfcn.h>


int checkperfect(int no) 
{
    void *lib=NULL;
    
  
    int (*fptr)(int);
    
    int ret=0;
    printf("Loading the library dynamically\n");

    lib=dlopen("./sumfactor.so",RTLD_LAZY);      //load library in memory (ram) and put in potential gap
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
    ret = fptr(no);
    if(ret==no){
       return 1;
    }
    else
    {
      return 0;
    }
   
    
    dlclose(lib);      //decrement the reference count  (ref count: how many process are using that library)
    
}







