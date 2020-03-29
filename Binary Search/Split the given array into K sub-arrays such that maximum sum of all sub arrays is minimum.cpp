//https://www.geeksforgeeks.org/split-the-given-array-into-k-sub-arrays-such-that-maximum-sum-of-all-sub-arrays-is-minimum/
int Min_Time(int arr[], int n, int k)
{
    int lo=1;
    int hi=0;
    for(int i=0;i<n;i++) hi+=arr[i];
    while(lo<=hi){
        int mid=(lo+hi)/2;
        bool check=true;
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
                check=false;
                break;
            }
            sum+=arr[i];
            if(sum>mid){
                cnt++;
                sum=arr[i];
            }
        }
        cnt++;
        if(cnt>k){
            check=false;
        }
        if(check){
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return lo;
}
