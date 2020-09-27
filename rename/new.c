#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){

    int ret=0;
   
    
    ret=rename("data.txt","Demo/Renamedata.txt");
 
   
    if(ret==-1){
       printf("unable to Rename file");
         return -1;
     }

  
    return 0;
}
/*
   if Renamedata.txt file is already present in Demo folder then the data gets overwritten so 
   use condition open directory check whether that Renamedata.txt is already present or not
 
*/
