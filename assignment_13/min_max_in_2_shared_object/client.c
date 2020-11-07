#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dlfcn.h>


int main() 
{
    void *libMax=NULL,*libMin=NULL;
    
    int (*fptr)(int[],int);
    int (*fptr1)(int[],int);
    int arr[]={1,4,3,5,6,7,8,9};
    int value1=10,value2=11,ret=0;
    printf("Loading the library dynamically\n");

    libMax=dlopen("./max.so",RTLD_LAZY);      //load library in memory (ram) and put in potential gap
                                               // rtld_lazy : run time load lazily
     
    if(libMax == NULL) {
       printf("Unable to link the library\n");
       return -1;
    }
    libMin=dlopen("./min.so",RTLD_LAZY);
    if(libMin == NULL) {
       printf("Unable to link the library\n");
       return -1;
    }
 
    printf("Libray Loaded Successfully\n");
    printf("Fetching the address of Min function\n");

    fptr= dlsym(libMax,"Max");  // to get address of function
    if(fptr == NULL) {
       printf("Unable to get address\n");
       return -1;
    }
    printf("Address of function fetched successfully\n");
    ret = fptr(arr,8);
     printf("Max is  %d\n",ret);

   //Min
   fptr1= dlsym(libMin,"Min");  // to get address of function
    if(fptr1 == NULL) {
       printf("Unable to get address\n");
       return -1;
    }
    printf("Address of function fetched successfully\n");
    ret = fptr1(arr,8);
     printf("Min is  %d\n",ret);
 
    
    dlclose(libMax); dlclose(libMin);      //decrement the reference count  (ref count: how many process are using that library)
    printf("Dynamic library unlinked\n");

    for(;;);
    return 0;
}







