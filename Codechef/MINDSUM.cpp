////***Sumit Kumar(sumit_011) ***********////

#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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


int digsum(int n) 
{ 
    int sum; 
  
    /* Single line that calculates sum */
    for (sum = 0; n > 0; sum += n % 10, n /= 10); 
  
    return sum; 
} 

int sum(int x,int y){
    return x+y;
}

signed main(){
     ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
	WL(t){
	    int n,d,min,pos;
	    bool flag=false;
	    cin>>n>>d;
	    int a[65536];
	    a[0]=n;
        
        if(n==1){
            debug2(1,0);
        }
        else{
	    for(int i=0;i<32767;i++){
	        a[2*i + 1]=digsum(a[i]);
	        if(a[2*i+1]==1) {           // if n==1 break and flag=true 
	            flag=true;
	            min=1;
	            pos=2*i+1;
	            break;
	        }
	        a[2*i + 2]=sum(a[i],d);
	    }
	    
	    if(flag){
	        debug2(min,(int)log2(pos+1));
	    }else{
	    min = a[0];
	    pos=0;
	    for(int i=0; i< 65536; i++) {
        if(a[i] < min)
        {
            min = a[i];
        }
    }
        for(int i=0; i< 65536; i++) {
        if(a[i]==min)
        {
            pos=i;
            break;
        }
        }
        debug2(min,(int)log2(pos+1));
	    }
    
        }
        
	   }
}
	

