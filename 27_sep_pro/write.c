#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0, ret = 0;
    char Buffer[30] = "  Marvellous";
    
    fd = open("Data.txt",O_WRONLY); // O_APPEND
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    
    lseek(fd,10,SEEK_SET);
    
    ret = write(fd,Buffer,10);
    if(ret == -1)
    {
        printf("Unable to write\n");
        return -1;
    }

    close(fd);
    return 0;
}




