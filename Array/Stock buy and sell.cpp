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


void solve(){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];
    vi v;
    rep(i,0,n-1){
        v.push_back(a[i+1]-a[i]);
    }
    bool flag = false;
    int cnt=0;
    rep(i,0,v.size()){
        if(v[i]>0 && cnt==0){
            flag=true;
            cnt=1;
            cout<<"("<<i<<" ";
        }
        if(v[i]<0 && cnt==1){
            flag=true;
            cnt=0;
            cout<<i<<") ";
        }
    }
    if(cnt==1){
        cout<<n-1<<")";
    }
    if(!flag){
        cout<<"No Profit";
    }
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
