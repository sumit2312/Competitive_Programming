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
#define vpii vector<pair<int,int>>
#define pqi priority_queue<int>
#define pqpii priority_queue<pair<int,int>>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

// Function to calculate min cost
int minCost(int a[],int n){
    priority_queue<int, vector<int>, greater<int> > pq(a, a + n);
    int ans=0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        ans += first + second;
        pq.push(first + second);
    }
    return ans;

}


void solve(){
   int n;
   cin>>n;
   int a[n];
   REP(i,n) cin>>a[i];
   debug(minCost(a,n));

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	WL(t){
	    solve();
	}

}
