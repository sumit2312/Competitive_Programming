#include<bits/stdc++.h>
using namespace std;

int ans(string &s,int l,int r,vector<vector<int> > &dp){
        if(l>r){
            return 0;
        }else if(l==r){
            return 1;
        }
        if(dp[l][r]!=-1) return dp[l][r];
        int x=0;
        if(s[l]==s[r]){
            x= ans(s,l+1,r-1,dp)+2;
        }else{
            x = max(ans(s,l+1,r,dp),ans(s,l,r-1,dp));
        }
        return dp[l][r]=x;
    }

int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<vector<int> > dp(n,vector<int> (n,-1));
    cout<<ans(s,0,n-1,dp);
    return 0;
}
