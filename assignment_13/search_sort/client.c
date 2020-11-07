#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dlfcn.h>


int main() 
{
    void *lib=NULL;
    int arr[]={1,4,3,2,3,7,4,9};
    //int add(int no1,int no2) 
    int (*fptr)(int[],int,int);
    int (*fptr1)(int[],int); 
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

    fptr= dlsym(lib,"search");  // to get address of function
    if(fptr == NULL) {
       printf("Unable to get address\n");
       return -1;
    }
    printf("Address of function fetched successfully\n");
    ret = fptr(arr,4,8);
    if(ret==1){
       printf("Element %d is found\n",4);
    } else{
       printf("Search %d is not fond\n",4);
    }
    

    //sub

    printf("Fetching the address of sort function\n");

    fptr1= dlsym(lib,"sort");
    if(fptr1 == NULL) {
       printf("Unable to get address\n");
       return -1;
    }
    printf("Address of function fetched successfully\n");
    fptr1(arr,8);
    //printf("sort is is %d\n",ret);

    dlclose(lib);      //decrement the reference count  (ref count: how many process are using that library)
    printf("Dynamic library unlinked\n");

    for(;;);
    return 0;
}







