
// Problem : D. Caesar's Legions
// Contest : Codeforces Beta Round #89 (Div. 2)
// URL : https://codeforces.com/contest/118/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

// Author - Sumit 
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define int ll
#define ps push
#define pb emplace_back
#define INF 10000000000000LL
#define MOD 100000000
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

int lo,hi; 

const int N=105;
int dp[N][N][15][15];

int ans(int f,int h,int k1,int k2){
	if((f+h)==0) return 1;
	
	if(dp[f][h][k1][k2]!=-1) return dp[f][h][k1][k2];
	
	int x=0;
	if(f>0 && k1>0) x=ans(f-1,h,k1-1,hi);
	
	int y=0;
	if(h>0 && k2>0) y=ans(f,h-1,lo,k2-1);
	
	return dp[f][h][k1][k2] = (x+y)%MOD;
}


void solve(){
	int n1,n2;
	cin>>n1>>n2>>lo>>hi;
	memset(dp,-1,sizeof(dp));
	int sol = ans(n1,n2,lo,hi);
	debug(sol);	
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
