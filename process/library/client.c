#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<library.h>

int main() 
{
    int value1=10,value2=11,ret=0;
    ret=add(value1,value2);
    printf("Addition is %d \n",ret);
    return 0;
}








