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

double distance(double x1,double y1,double x2,double y2){
    double x= pow((pow(abs(x1-x2),2) + pow(abs(y1-y2),2)),0.5);
    return x;
}

signed main(){
     ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	int q;
	cin>>n>>q;
	double x[n],y[n],r[n];
	REP(i,n) {
	   cin>>x[i]>>y[i]>>r[i];
	}

    vi a,b;
	    
	    FOR(i,0,n-1){
	        FOR(j,i+1,n){
	            
	            double mx,mn;
	            double x1,x2,y1,y2,r1,r2;
	            x1=x[i];
	            y1=y[i];
	            x2=x[j];
	            y2=y[j];
	            r1=r[i];
	            r2=r[j];
	            double d=distance(x1,y1,x2,y2);
	         
	         
	         if(d-r1-r2>=0){
	             mn=d-r1-r2;
	         }
	         else if((d-abs(r1-r2))<=0){
	             mn=abs(r1-r2)-d;
	         }
	         else{
	             mn=0;
	         }
	         mx=d+r1+r2;
	         
	         
	        a.push_back(ceil(mn));
	        b.push_back(floor(mx)+1);
	       // debug2(ceil(mn),floor(mx));
	        }
	    }
	     sort(a.begin(),a.end());
	     sort(b.begin(),b.end());
	     //cout<<a[0]<<b[0]<<"\n";
	     
	     while(q--){
	         int k;
	         cin>>k;
	         int u,v;
	         u = upper_bound(a.begin(),a.end(), k)-a.begin();
	         v = upper_bound(b.begin(),b.end(), k)-b.begin();
           // debug2(u,v);
            cout<<abs(u-v)<<"\n";
	     }
	    
	
	
}
