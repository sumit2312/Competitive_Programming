// Author - Sumit 

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)
const int mod = 1e9+7;
using ll = long long int;
#define int ll
#define pb push_back
#define debug(x) cout << x << "\n";
#define debug2(x,y) cout << x << " " << y << "\n";
#define debug3(x,y,z) cout << x << " " << y << " " << z << "\n";

const int N=1e6+5;
vector<int> v[N];
//bool vis[N];
int color[N];
int grp[N];
int col=0;
int n,m;

int dfs(int p){
    if(color[p])
        return 0;
    // cout<<p<<" ";
    color[p]=col;
    int ans = (p<=n?1:0);
    for(auto x:v[p])
        ans+=dfs(x);
    return ans;
}

void solve(){
    cin>>n>>m;
    rep(i,1,m+1){
        int sz;
        cin>>sz;
        rep(j,0,sz){
            int x;
            cin>>x;
            v[x].pb(i+n);
            v[i+n].pb(x);
        }
    }
    rep(i,1,n+1){
        if(!color[i]){
            col++;
            grp[col]=dfs(i);
            //cout<<endl;
        }

        cout<<grp[color[i]]<<" ";
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
    //cin>>t;
    while(t--){
        solve();
    }
}
