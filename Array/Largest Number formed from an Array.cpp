// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0/

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

bool cmp(int x,int y){
    string a = to_string(x);
    string b = to_string(y);
    string xx = a+b;
    string yy = b+a;
    return xx>yy;
}


void solve(){
    int n;
    cin>>n;
    int arr[n];
    rep(i,0,n) cin>>arr[i];
    sort(arr,arr+n,cmp);
    for(auto x:arr) cout<<x<<"";
    cout<<endl;
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
