////***Sumit Kumar***********////

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define ps push
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define remax(a, b) a = max(a, b)
#define remin(a, b) a = min(a, b)
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define F first
#define S second
#define mii map<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int, int>>
#define pqi priority_queue<int>
#define pqpii priority_queue<pair<int, int>>
#define itr ::iterator it
#define WL(t) while (t--)
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) * (b)) / gcd((a), (b))
#define debug(x) cout << x << endl;
#define debug2(x, y) cout << x << " " << y << endl;
#define debug3(x, y, z) cout << x << " " << y << " " << z << endl;

void solve() {
    int n;
    cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    int i,j;
    for(i=n-2;i>=0;i--){
        if(a[i]<a[i+1])
        break;
    }
    if(i==-1){
        cout<<-1<<endl;
        
    }else{
    for(j=i+1;j<n;j++){
        if(a[j]<=a[i]){
            break;
        }
    }
    swap(a[i],a[j-1]);
    sort(a+i+1,a+n);
    REP(i,n){
        cout<<a[i];
    }
    cout<<endl;
    }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  WL(t) { solve(); }
}
