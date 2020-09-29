#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    
    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    }
    
    ret = lseek(fd,1024,SEEK_END);
    printf("%d",ret);
    
    write(fd," ",1);
    
    close(fd);
    return 0;
}





















/*
    printf("Marvellous Infosystems");
 
    write(1,"Marvellous",10);

 */
