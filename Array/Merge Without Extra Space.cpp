void merge(int a[], int b[], int n, int m){
    int i=n-1,j=0;
    while(i>=0 && j<m){
        if(a[i]>b[j]){
            swap(a[i],b[j]);
            i--;
            j++;
        }else{
            j++;
        }
    }
    sort(a,a+n);
    sort(b,b+m);
    
} 
