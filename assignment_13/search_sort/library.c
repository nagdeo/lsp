
int search(int arr[],int key,int len) 
{
    int i=0;
   for(i=0;i<len;i++){
      if(arr[i]==key){
          break;
      }
   }
   if(i==len){
     return 0;
   } else{
     return 1;
   }
}

void sort(int arr[], int len) 
{
   printf("Array before sort\n");
   for(int i=0;i<len;i++){
    printf("%d ",arr[i]);
   }
     int temp=0;
   for(int i=0;i<len-1;i++){
     for(int j=i+1;j<len;j++){
        
         if(arr[i]>arr[j]){
              temp=arr[i];
              arr[i]=arr[j];
              arr[j]=temp;
         }
     }
   }
   printf("\n");
   printf("Array after sort\n");
  for(int i=0;i<len;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}








