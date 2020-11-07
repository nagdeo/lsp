#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dlfcn.h>


int main() 
{
    void *lib=NULL;
    
  
    int (*fptr)(int);
    
      int no=0,ret=0;
    printf("Loading the library dynamically\n");

    lib=dlopen("./checkperfect.so",RTLD_LAZY);      //load library in memory (ram) and put in potential gap
                                               // rtld_lazy : run time load lazily
    if(lib == NULL) {
       printf("Unable to link the library\n");
       return -1;
    }
    printf("Libray Loaded Successfully\n");
   printf("Enter the no.: \n");
    scanf("%d",&no);
    printf("Fetching the address of checkperfect function\n");

    fptr= dlsym(lib,"checkperfect");  // to get address of function
    if(fptr == NULL) {
       printf("Unable to get address\n");
       return -1;
    }
    printf("Address of function fetched successfully\n");
    ret = fptr(no);
    if(ret==1){
      printf("%d is perfect\n",no);
    }else{
      printf("%d is not perfect\n",no);
    }
    
    dlclose(lib);      //decrement the reference count  (ref count: how many process are using that library)
    printf("Dynamic library unlinked\n");

    for(;;);
    return 0;
}







