// Author - Sumit 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define ps push
#define pb emplace_back
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
#define debug(x) cout << x << "\n";
#define debug2(x,y) cout << x << " " << y << "\n";
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

template<typename T, typename U> inline void remin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void remax(T &x, U y) { if(x < y) x = y; }

const int N=1e5+5;
vi v[N];
int sz[N];

void dfs(int p){
    if(v[p].size()==0){
        sz[p]=1;
    }
    for(auto x:v[p]){
        dfs(x);
        sz[p]+=sz[x];
    }
}


void solve(){
    int n;
    cin>>n;
    rep(i,2,n+1){
        int x;
        cin>>x;
        v[x].pb(i);
    }
    dfs(1);
    sort(sz+1,sz+n+1);
    rep(i,1,n+1){
        cout<<sz[i]<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
