#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){

    int fd=0,ret=0,end=0;
    //char buffer[1024];
    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    }
    
    ret = lseek(fd,0,SEEK_END);
    printf("%d",ret);
    
    //
    for(int i=0;i<1024;i++){
       pwrite(fd," ",1,ret+i);
       end=ret+i;
     }
     write(fd,"hole",4);
     for(int i=0;i<5;i++){
       pwrite(fd," ",1,end+i);
       end=ret+i;
     }
    
    close(fd);
    return 0;

}

    
    
