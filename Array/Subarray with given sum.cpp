// Author - sumit_011

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

void subarray(int a[],int n,int s){
  // Initialising all the required variables 
    int header=0,flag=0,sum=0;
  // Sliding window 
    for(int i=0;i<n;i++){
        sum+=a[i];    // Adding elements to the  window
        while(sum>s){    // Remove element till winndow sum is less than req sum
            sum-=a[header];
            header++;
        }
        // Check given sum is equal to window sum
        if(sum==s){
            debug2(header+1,i+1);
            flag=1;
            break;
        }
    }
    if(flag==0){
        debug(-1);
    }
}


void solve(){
    int n,s;
    cin>>n>>s;
    int a[n];
    rep(i,0,n) cin>>a[i];
    subarray(a,n,s);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t=1;
    cin>>t;
    WL(t){
        solve();
    }
    
}
