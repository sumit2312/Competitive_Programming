// Author - Sumit

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int ll
#define ps push
#define pb push_back
#define INF 1000000000
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
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int CircularSearch(int A[],int n,int x){
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(x == A[mid]) return mid; // Case1 : Found x
        if(A[mid]<=A[high]){ // Case2 : right half is sorted
            if(x>A[mid] && x<=A[high]){
                low=mid+1;  // go search in right sorted half
            }else{
                high=mid-1; //go search left
            }
        }else{   // Case3 : Left half is sorted
            if(A[low]<=x && x<A[mid])
                high=mid-1;  // go search in left sorted half
            else
                low=mid+1;   // go search right
        }
    }
    return -1;
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];
    int x;cin>>x;
    debug(CircularSearch(a,n,x));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
                        
    int t=1; 
    cin>>t;
    WL(t){
        solve();
    }    
}
