/*
Classic Combinatorics. If you have 2 groups of size A , B and you want to form a pair
of 2 people belonging to different groups. You can do that in A * B ways. If we have 
an additional group C included to the question, then we should count ways where there 
is a member from C and we can take him along with one of the (A+B) other people. Son
C * (A + B) is added to our answer. We have already included pairs where people in belong 
to A,B so we need to add new pairs. If we add a group with size D we need to add D * (A + B + C) in the same manner.

*/
////***Sumit Kumar***********////

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int ll
#define ps push
#define pb push_back
#define INF 100005
#define MOD 1000000007
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
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

vi v[INF];
bool vis[INF];
int c=0;

void dfs(int p){
    c++;
    vis[p]=true;
    int sz=v[p].size();
    REP(i,sz){
        if(vis[v[p][i]]==false){
            dfs(v[p][i]);
        }
    }
}


void solve(){
    int n,p;
    cin>>n>>p;
    REP(i,p){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    vi arr;
    REP(i,n){
        c=0;
        if(vis[i]==false){
            dfs(i);
            arr.pb(c);
        }
    }
    int pre[arr.size()];
    pre[0]=arr[0];
    FOR(i,1,arr.size()){
        pre[i]=pre[i-1]+arr[i];
    }
    int ans=0;
    FOR(i,0,arr.size()-1){
        ans+=arr[i+1]*pre[i];
    }
    debug(ans);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//  cin>>t;
    WL(t){
        solve();
    }
    
}
