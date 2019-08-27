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

const int N=1e5;
vi g[N];
int color[N];
bool flag;

void dfs(int v, int p){
  color[v] = 1; // GREY
  for(int w : g[v]){
    if(color[w] == 1){
        flag=true;  // you found a cycle, it's easy to recover it now.      
    }
    if(color[w] == 0) dfs(w, v);
  }
  debug(v);
  color[v] = 2; // BLACK
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
    }    

    for(int i = 1; i <=n; i++)
        if(color[i] == 0) dfs(i, -1); // IF NODE IS WHITE, START NEW DFS

    // debug(flag);
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
    // cin>>t;
    WL(t){
        solve();
    }    
}
