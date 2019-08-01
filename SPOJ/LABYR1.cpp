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
 
 
const int N = 1005;
int mxlen=0,len=0;
int a,b;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,-1,1};
int c,r;
 
char arr[N][N];
bool vis[N][N];
 
void dfs(int x,int y){
  len++;
  // cout<<x<<y<<endl;
  if(len>mxlen){
    a=x;
    b=y;
    mxlen = len;
  }
  vis[x][y]=true;
  rep(i,0,4){
    int X=x+dx[i];
    int Y=y+dy[i];
    if(X>=0 && Y>=0 && X<r && Y<c && vis[X][Y]==false && arr[X][Y]=='.'){
      dfs(X,Y);
    }
  }
  len--;
}
 
 
void solve(){  
  memset(arr,0,sizeof(arr));
  memset(vis,false,sizeof(vis));
  cin>>c>>r;
  bool ok = false;
  int cx=0,cy=0;
  rep(i,0,r){
    rep(j,0,c){
      cin>>arr[i][j];
      if(arr[i][j]=='.'&& (!ok)){
        cx=i;
        cy=j;
        ok = true; 
      }
    }
  }
  mxlen=0;
  len=0;
  // debug2(cx,cy);
  dfs(cx,cy);
  memset(vis,false,sizeof(vis));
  mxlen=0;
  len=0;
  dfs(a,b);
  // debug2(a,b);
  cout<<"Maximum rope length is "<<mxlen-1<<"."<<endl;
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
