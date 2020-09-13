#include<stdio.h>

int main(int argc,char *argv[]){

   if(argc!=2){
      printf("Invalid no. of arguments.");
      return -1;
   }
   printf("Command line argument is:%s",argv[1]);
   return 0;
}
