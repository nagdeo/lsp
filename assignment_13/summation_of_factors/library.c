
int factorSum(int no) 
{
    int i=0,sum=0;
   for(i=no/2;i>=1;i--){
      if(no%i==0){
         sum=sum+i;
      }
   }
   
     return sum;
   
}








