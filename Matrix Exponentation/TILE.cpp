
// Problem : Easy Tiling
// Contest : CodeChef - Practice(Extcontest)
// URL : https://www.codechef.com/problems/TILE
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
 
void mul(int a[2][2],int b[2][2]){
	int x=((a[0][0]*b[0][0])%MOD + (a[0][1]*b[1][0])%MOD)%MOD;
	int y=((a[0][0]*b[0][1])%MOD + (a[0][1]*b[1][1])%MOD)%MOD;
	int z=((a[1][0]*b[0][0])%MOD + (a[1][1]*b[1][0])%MOD)%MOD;
	int w=((a[1][0]*b[0][1])%MOD + (a[1][1]*b[1][1])%MOD)%MOD;
	
	a[0][0]=x;
	a[0][1]=y;
	a[1][0]=z;
	a[1][1]=w;
}

int power(int f[2][2],int n){
	int m[2][2]={{1,1},{1,0}};
	if(n==1) return f[0][0]+f[0][1];
	power(f,n/2);
	mul(f,f);
	if(n&1) mul(f,m);
	return f[0][0]+f[0][1];
}

int fib(int n){
	int f[2][2]={{1,1},{1,0}};
	if(n==1 || n==0) return 1;
	return power(f,n-1);
}

void solve(){
	int n;
	cin>>n;
    debug(fib(n)%MOD);
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
