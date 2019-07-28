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
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int,int>>
#define pqi priority_queue<int>
#define pqpii priority_queue<pair<int,int>>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;


int cnt=1;   
vi v[1000005];
bool vis[1000005];
bool ans=0;
bool color[1000005];

// Check for Bipartite
void dfs(int p,bool col){
    vis[p] = true;color[p]=col;
    for(auto x:v[p]){
        if(!vis[x]){
            dfs(x,1-col);
        }
        else{
            if(color[x]==col)
                ans=1;
        }
    }
}

void solve(){
    memset(vis,false,sizeof(vis));
    int n,m;
    cin>>n>>m;
    rep(i,0,1000005) v[i].clear();
    memset(color,false,sizeof(color));
    ans=0;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    rep(i,1,n+1){
        if(!vis[i])
            dfs(i,0);
    } 
    cout<<"Scenario #"<<cnt<<":\n";
    if(ans){
        cout<<"Suspicious bugs found!\n";
    }else{
        cout<<"No suspicious bugs found!\n";
    }
    cnt++;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;     
	WL(t){        
	    solve();
	}
	
}
