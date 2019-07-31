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

const int N=1e6+5;
int dis[N];
bool vis[N];
int f,s,g,u,d;


void bfs(){
  queue<int> q;
  vis[s]=true;
  q.push(s);
  dis[s]=0;
  int nxt,pre;
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    nxt = curr + u;
    pre = curr - d;
    if(nxt<=f && !vis[nxt]){
      vis[nxt]=true;
      dis[nxt]=dis[curr]+1;
      q.push(nxt);
    }
    if(pre>=1 && !vis[pre]){
      vis[pre]=true;
      dis[pre]=dis[curr]+1;
      q.push(pre);
    }
  }
}

void solve(){ 
  
  cin>>f>>s>>g>>u>>d;
  dis[g]=-1;
  bfs();
  if(dis[g]==-1){
    debug("use the stairs");
  }else{
    debug(dis[g]);
  }
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
