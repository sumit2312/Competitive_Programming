//https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0/?ref=self

/* QUE - 
Given an array, the task is to divide it into two sets S1 and S2 such that 
the absolute difference between their sums is minimum.
*/

/*
SIMPLE APPROACH:Follow subset sum problem,if subset sum exists then find the max value of sum 
possible between 1 and sum/2,let this be m. Then diff is given by (sum-m)-m or sum-2*m.
Example
For input: 1 5 6 11
The sum is 23, sum/2=11;
Between 1 and 11 maximum existing subset sum is 11,
diff= 23-11-11=1;
*/

// Author - Sumit

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int ll
#define ps push
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)
#define repd(i,a,b) for (int i = a; i >= b; i--)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int,int>>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
 

class Solution {
public:
    int canPartition(vector<int>& arr) {

    int n=arr.size();
    int sum = accumulate(all(arr),0);    
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<=sum;i++)
        dp[0][i]=false;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[i-1])
                dp[i][j]=dp[i-1][j];
            else if(j>=arr[i-1])
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }
    int m=INT_MIN;
    for(int i=1;i<=sum;i++)
    {
        if(dp[n][i]==true && 2*i<=sum)
        {
            m=max(m,i);
        }
    }
    int diff=(sum-m)-m;
    return diff;        
    }
};


void solve(){
    int n;
    cin>>n;
    vi v;
    
    rep(i,0,n){
        int x;cin>>x;
        v.emplace_back(x);
    }
    Solution s;
    debug(s.canPartition(v));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t=1;
    cin>>t;
    WL(t){
        solve();
    }    
}
