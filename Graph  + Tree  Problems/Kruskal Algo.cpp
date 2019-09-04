// Author - Sumit

#include<bits/stdc++.h> 
using namespace std;
 
#define ll long long int
#define ps push
#define pb push_back
#define INF 10000000
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

const int N=10005;
int nodes,edges;
int id[N];
pair<int,pii> p[N];

void init(){
    rep(i,0,N)
        id[i]=i;
}

int root(int x){
    while(id[x]!=x){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}

void union1(int x,int y){
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}

int kruskal(pair<int,pii> p[]){
    int x,y;
    int cost,minCost=0;
    rep(i,0,edges){
        x=p[i].S.F;
        y=p[i].S.S;
        cost=p[i].F;
        if(root(x)!=root(y)){
            minCost+=cost;
            union1(x,y);
        }
    }
    return minCost;
}


void solve(){
    init();
    int wt,minCost;
    cin>>nodes>>edges;
    rep(i,0,edges){
        int x,y;
        cin>>x>>y>>wt;
        p[i]=mp(wt,mp(x,y));
    }
    sort(p,p+edges);
    minCost=kruskal(p);
    debug(minCost);
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
