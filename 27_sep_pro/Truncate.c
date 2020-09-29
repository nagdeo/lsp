#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    
    ret = truncate(argv[1],15);
    if(ret == -1)
    {
        printf("Unable to truncate\n");
    }
    
    printf("%d",ret);
    
    fd = open("Temp.txt",O_WRONLY);
    
    ret = ftruncate(fd,15);
    
    return 0;
}



























/*
    printf("Marvellous Infosystems");
 
    write(1,"Marvellous",10);

 */
