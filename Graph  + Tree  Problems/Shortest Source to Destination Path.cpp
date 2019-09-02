// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0

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

const int N=25;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};


void solve(){
    int n,m;
    int desi,desj;
    cin>>n>>m;
    int a[n][m];
    int vis[m][m];
    rep(i,0,n){
        rep(j,0,m){
            cin>>a[i][j];
        }
    }
    cin>>desi>>desj;
    

    if(a[0][0]==0){
        cout<<-1<<endl;
        return;
    }

    memset(vis,false,sizeof(vis));
    queue<pair<pair<int,int>,int> > q;
    int ans=-1;

    q.push({{0,0},0});
    vis[0][0]=true;
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int steps = q.front().second;
        // debug3(r,c,steps);
        q.pop();
        
        if(r==desi && c==desj){
            ans=steps;
            break;
        }
        rep(i,0,4){
            int rr=r+dx[i];
            int cc=c+dy[i];
            if(rr<0 || cc<0 || rr>=n || cc>=m) continue;    
            if(!vis[rr][cc] && a[rr][cc]==1){
                vis[rr][cc]=true;
                q.push({{rr,cc},steps+1});
            }
        }
    }
    cout<<ans<<endl;
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
