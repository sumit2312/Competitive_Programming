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
      ll n,k;
      cin>>n>>k;
      ll a[n];
      REP(i,n) cin>>a[i];
      ll ans = k;
      REP(i,n){
          if(a[i]<=ans){
              cout<<"1";
              ans = ans - a[i];
          }
          else
          {
              cout<<"0";
          }
      }
      cout<<"\n";
      
    }
}
