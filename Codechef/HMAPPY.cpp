////***Sumit Kumar(sumit_011) ***********////

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int ll
#define ps push
#define pb push_back
#define INF 1000000
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
int n,m;
int a[INF],b[INF];
int A[INF],B[INF];

bool answer(int p)
{
    int q1,q2,count=0,mx; 
    mx=m;    
    REP(i,n) B[i]=A[i];
    REP(i,n){
        int q=B[i];
        if((q-p>0)&&mx>0)
        {
            q1=(q-p)/b[i];
            q2=(q-p)%b[i];
            if(q2==0&&(mx-q1)>=0)
            {
                mx-=q1;
                B[i]-=(q1*b[i]);
            }
            else if((mx-q1-1)>=0&& q2!=0)
            {
                mx-=(q1+1);
                B[i]-=((q1+1)*b[i]);
            }
            else
            break;
        }
    }
    REP(i,n){
        if(B[i]<=p)
        count++;
    }
    if(count==n)
    return true;
    else
    return false;
}

signed main(){
     ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    REP(i,n) A[i]=a[i]*b[i];
    int ans,max=-1;
    REP(i,n){
        if(A[i]>max)
            max=A[i];
    }

    int min=0,mid;
  
    while(min<=max){
        mid=(min+max)/2;
        if(answer(mid)){
            ans=mid;
            max=mid-1;
        }else{
            min=mid+1;
        }
    }
    
    debug(ans);
}
