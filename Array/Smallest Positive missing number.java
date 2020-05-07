// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number3051/1/?track=ppc-arrays&batchId=221

class FindMissing{
    
    // Function to find 
    static int findMissing(int a[], int n)
    {
       
       for(int i=0;i<n;i++){
           while(a[i]>0 && a[i]<=n && a[a[i]-1]!=a[i])
           {
               int temp=a[a[i]-1 ];
               a[a[i]-1 ]=a[i];
               a[i]=temp;
           }
       }
       for(int i=0;i<n;i++){
           if(a[i]!=i+1){
               return i+1;
           }
       }
       return n+1;
    }
}
