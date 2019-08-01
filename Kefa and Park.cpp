// Author - sumit083

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

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,mx;
const int N=100005;
int a[N],cnt[N];
vi v[N];
bool vis[N];
int ans;

void dfs(int p){
    vis[p]=true;
    if(cnt[p]<=mx && p!=1 && v[p].size()==1) ans++;

    for(auto x:v[p]){
        if(!vis[x]){
            cnt[x] = cnt[p]+a[x];
            if(cnt[x]<=mx && a[x]==0) cnt[x]=0;
            dfs(x);
        }
    }
}


void solve(){  
    cin>>n>>mx;
    rep(i,1,n+1) cin>>a[i];
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    cnt[1]=a[1];
    dfs(1);
    debug(ans);
    // rep(i,1,n+1) cout<<cnt[i]<<" ";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t=1;
    // cin>>t;
    WL(t){
        solve();
    }
    
} 
