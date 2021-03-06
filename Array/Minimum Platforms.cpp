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

void solve(){
    int n;
    cin>>n;
    int A[n],D[n];
    rep(i,0,n) cin>>A[i];
    rep(i,0,n) cin>>D[i];
    sort(A,A+n);
    sort(D,D+n);
    int ans=1,platform=1;
    int i=1,j=0;
    while(i<n && j<n){
        if(A[i]<=D[j]){
            platform++;
            i++;
            if(platform>ans){
                ans=platform;
            }
        }else{
            j++;
            platform--;
        }
    }
    debug(ans);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
                        
    int t=1;
    cin>>t;
    WL(t){
        solve();
    }    
}
