// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/

class Celebrity
{
    // The task is to complete this function
    int getId(int M[][], int n)
    {
        int[] InNode = new int[n];
        int[] OutNode = new int[n];
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
               if(M[i][j]==1){
                   InNode[j]++;
                   cnt++;
               } 
            }
            if(cnt>0){
                OutNode[i]++;
            }
        }
        // bool f = false;
        for(int i=0;i<n;i++){
            if(InNode[i]==n-1 && OutNode[i]==0){
                // f = true;
                return i;
            }
        }
        return -1;
    }
    
}
