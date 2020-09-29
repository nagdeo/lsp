#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0, ret = 0;
    char Buffer[30];
    char path[60] = {'\0'};
    
    fd = symlink("Data.txt","Myshortcut.txt");
    if(fd == -1)
    {
        printf("Unable to create symbolic link");
        return -1;
    }
    
    printf("Link created\n");
    
    fd = open("Myshortcut.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    
   ret = read(fd,Buffer,30);
    
    printf("Data from the symbolic link through read is : \n");
    write(1,Buffer,ret);
    
    ret = readlink("Myshortcut.txt",path,60);
    printf("\nData from the symbolic link through readlink is : \n");
    write(1,path,ret);
    
    printf("\n");
    
    close(fd);
    return 0;
}




