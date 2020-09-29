#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int ret = 0;
    
    //                  "Old filename", "New file name"
    ret = rename("Data.txt","LSP/RenamedData.txt");
    
    if(ret == -1)
    {
        printf("Failure in rename\n");
    }
    
    printf("Rename Succesfull\n");
    
    return 0;
}




