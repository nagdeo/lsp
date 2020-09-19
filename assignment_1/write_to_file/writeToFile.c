#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int fd=0;
    int iret=0,i=0;
    char arr[20];
    printf("Enter File name:\n");
    char filename[50]; 
    scanf("%[^\n]%*c", filename);
    printf("Enter String:\n"); 
    scanf("%[^\n]%*c", arr);
    fd=open(filename,O_WRONLY);
    for (i = 0; arr[i] != '\0'; ++i);
    if(fd==-1){
      printf("Unable to open file\n");
    }
    else{
       printf("File opened successfully with fd: %d\n",fd);
    }
    
    iret=write(fd,arr,i);

    if(iret==-1){
      printf("Unable to write\n");
      close(fd);
      return -1;
    }
    printf("Data gets written in the file successfully\n");
    close(fd);
    return 0;
}
