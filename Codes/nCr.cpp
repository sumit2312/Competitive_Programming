int NCR(int n,int r){
    int p=1,k=1;
    if(n-r<r)
        r=n-r;
    if(r==0){
        return (1);
    }
    while(r){
        p*=n;
        k*=r;
        int m=gcd(p,k);
        p/=m;
        k/=m;
        n--;
        r--;
    }
    return p;
}
