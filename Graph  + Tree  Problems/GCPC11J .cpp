////***Sumit Kumar***********////

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


const int N=1e5+5;
vi v[N];
bool vis[N];

int mxlen;
int node;
//find max dist from a node
void dfs(int p,int len){
  if(len>mxlen){
    mxlen = len;
    node = p;
  }
  vis[p]=true;
  for(auto x:v[p]){
    if(!vis[x])
      dfs(x,len+1);
  }
}


void solve(){ 
  memset(vis,false,sizeof(vis));
  rep(i,0,N) v[i].clear();

  int n;
  cin>>n;
  rep(i,0,n-1){
    int x,y;
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
  }
  mxlen=0;
  rep(i,0,n){
    if(!vis[i]){
      dfs(i,0);
      break;
    }
  }
  memset(vis,false,sizeof(vis));
  mxlen=-1;
  dfs(node,0);
  int ans = ceil((1.0*mxlen)/(2.0));
  debug(ans);
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
