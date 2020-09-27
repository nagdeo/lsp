#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    int no1=0,no2=0,no3=0,ans=0;
    printf("Enter three numbers\n");
    scanf("%d %d %d",&no1,&no2,&no3);

    ans=no1+no2+no3;
    printf("Addition is : %d \n",ans);
  
  return 0;
}

