// https://practice.geeksforgeeks.org/problems/cutted-segments/0

/*
Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut 
length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total 
number of cutted segments must be maximum. 
*/

const int N=4005;
int dp[N];

int go(int n,int x,int y,int z){
    if(n<0){
        return INT_MIN;
    }
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    // int ans=0;
    int a = 1+go(n-x,x,y,z);
    int b = 1+go(n-y,x,y,z);
    int c = 1+go(n-z,x,y,z);
    return dp[n] = max(a,max(b,c));
}

void solve(){
    int n;cin>>n;
    int x,y,z;cin>>x>>y>>z;
    memset(dp,-1,sizeof dp);
    int ans = go(n,x,y,z);
    ans=max(ans,0LL);
    debug(ans);
}
