// SPOJ  - ACODE - Alphacode  

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

int t;

int solve(string s){
    int n = s.size();
    if(s[0]=='0')return 0;
    int input[n+1];
    input[0]=1;input[1]=1;
    for(int i=2;i<=n;i++){
        input[i]=0;
        if(s[i-1]>'0')input[i]=input[i-1];
        if(s[i-2]=='1'||(s[i-2]=='2' && s[i-1]<'7'))
            input[i]+=input[i-2];
    }
    return input[n];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
    string s;
	while(cin>>s && s[0]!='0'){
	  debug(solve(s));
	}
	
}
