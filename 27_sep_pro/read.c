#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0, ret = 0;
    char Buffer[30];
    
    fd = open("Data.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    
    lseek(fd,10,SEEK_SET);
    
    ret = read(fd,Buffer,30);
    
    printf("Data is : \n");
    
    write(1,Buffer,ret);
    
    printf("\n");
    
    close(fd);
    return 0;
}




