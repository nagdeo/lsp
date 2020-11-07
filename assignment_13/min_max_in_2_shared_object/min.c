
int Min(int arr[],int len) 
{
    int i=0,min=0;
   min=arr[0];
   for(i=0;i<len;i++){
      if(arr[i]<min){
         min=arr[i];
      }
   }
   
     return min;
   
}








