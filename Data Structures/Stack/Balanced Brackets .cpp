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

void solve(){
    string s;
    cin>>s;
    bool flag = true;
    vector<char> v;
    REP(i,s.size()){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            v.pb(s[i]);
        }
        if(v.size()==0){
            flag=false;
            break;
        }
        if(s[i]=='}'){
            if(v.back()=='{'){
                v.pop_back();
            }else{
            //   debug("NO");
            flag = false;
              break;
            }
        }
        if(s[i]==']'){
          if (v.back() == '[') {
            v.pop_back();
          } else {
            // debug("NO");
            flag = false;
            break;
          }
        }
        if(s[i]==')'){
          if (v.back() == '(') {
            v.pop_back();
          } else {
            // debug("NO");
            // return;
            flag = false;
            break;
           
          }
        }
        
    }
    if(v.size()!=0){
        flag = false;
    }
    if(flag){
        debug("YES");
    }else{
        debug("NO");
    }
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
