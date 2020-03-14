
// Problem : Adjacent Bit Counts
// Contest : SPOJ - Classical
// URL : https://www.spoj.com/problems/GNYR09F/
// Memory Limit : 1536 MB
// Time Limit : 3000 ms

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

const int N=102;
int dp[N][N][2];

int ans(int n,int k,int f){
    if(n==0) return 0;
    if(n==1){
        if(k==0){
            return 1;
        }else{
            return 0;
        }
    } 
    if(dp[n][k][f]!=-1){
        return dp[n][k][f];
    }
    int res=-1;
    if(f==1){
        res = ans(n-1,k-1,1)+ ans(n-1,k,0); 
    }else{
        res = ans(n-1,k,1)+ ans(n-1,k,0);
    }
    return dp[n][k][f]=res;
}

void solve(){
    int id,n,k;
    cin>>id>>n>>k;
    int res = ans(n,k,0);
    res+=ans(n,k,1);
    debug2(id,res);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t=1;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        solve();
    }
}
