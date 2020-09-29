#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;
    
    fd = symlink("Data.txt","Myshortcut.txt");
    if(fd == -1)
    {
        printf("Unable to create symbolic link");
        return -1;
    }
    
    printf("Link created\n");
    return 0;
}
