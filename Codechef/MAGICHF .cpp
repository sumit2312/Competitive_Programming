#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
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
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int t;
 
signed main(){
     ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> t;
	WL(t){
	  ll n,x,s;
	  cin>>n>>x>>s;
	  ll a[n];
	  REP(i,n) a[i]=-1;
	  ll ans = x;
	  a[x-1] = -2;
	  while(s--){
	      ll p,q;
	      cin>>p>>q;
	      swap(a[p-1],a[q-1]);
	      if(a[p-1]==-2)
	      ans = p;
	      else if(a[q-1]==-2)
	      ans = q;
	  }
	  cout<<ans<<"\n";
	}
}
