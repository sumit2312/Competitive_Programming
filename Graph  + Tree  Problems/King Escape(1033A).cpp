
// Problem : A. King Escape
// Contest : Lyft Level 5 Challenge 2018 - Elimination Round
// URL : https://codeforces.com/contest/1033/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

// Author - Sumit 
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define int ll
#define ps push
#define pb emplace_back
#define INF 10000000000000LL
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
#define lower(v,x) (lower_bound(all(v),x)-v.begin())
#define upper(v,x) (upper_bound(all(v),x)-v.begin())
#define debug(x) cout << x << "\n";
#define debug2(x,y) cout << x << " " << y << "\n";
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
 
template<typename T, typename U> inline void remin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void remax(T &x, U y) { if(x < y) x = y; }
template<typename T> T pow(T a,T b, int m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=1005;
int vis[N][N];
int n,ax,ay,bx,by,cx,cy;

void dfs(int x,int y){
	if(x<1 or x>n or y<1 or y>n or vis[x][y]==1 or (x==ax or y==ay or abs(x-ax)==abs(y-ay))) return;
	vis[x][y]=1;
	if(x==cx and y==cy){
		debug("YES");
		exit(0);
	} 
	rep(i,-1,2){
		rep(j,-1,2){
			if(i==0 and j==0) continue;
			dfs(x+i,y+j);
		}
	}
}


void solve(){
	cin>>n;
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	dfs(bx,by);
	debug("NO");
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
