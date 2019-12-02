////***Sumit Kumar(sumit_011) ***********////
 
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
 
 
void buildTree(int *tree,int *a,int index,int s,int e){
    
    //Base Case - Leaf Node
    if(s==e){
        tree[index]=a[s];
        return;
    }
    
    //Recursive Case
    int mid=(s+e)/2;
    buildTree(tree,a,2*index,s,mid);
    buildTree(tree,a,2*index+1,mid+1,e);
    
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}
 
int query(int *tree,int index,int s,int e,int qs,int qe){
    // 3 Cases
    
    // 1.No Overlap
    if(qs>e||qe<s){
        return INF;
    }
    //2. Complete Overlap
    if(s>=qs && e<=qe){
        return tree[index];
    }
    
    // 3. Partial overlap - Call both Sides
    int mid=(s+e)/2;
    int leftAns = query(tree,2*index,s,mid,qs,qe);
    int rightAns = query(tree,2*index+1,mid+1,e,qs,qe);
    
    return min(leftAns,rightAns);
}
 
void updateNode(int *tree,int index,int s,int e,int i,int value){
    //NO overlap
    if(i<s||i>e){
        return;
    }
    //Reached leaf Node
    if(s==e){
        tree[index]=value;
        return;
    }
   // Lying in range - i is lying in between s and e
   int mid = (s+e)/2;
   updateNode(tree,2*index,s,mid,i,value);
   updateNode(tree,2*index+1,mid+1,e,i,value);
   tree[index] = min(tree[2*index],tree[2*index+1]);
   return;
}
 
signed main(){
     ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	
	int n,q,i,l,r;
	char ch;
    cin>>n>>q;
    int a[n+1];
    for(i=1;i<=n;i++)
    cin>>a[i];
    int *tree = new int[4*n+1];
    buildTree(tree,a,1,1,n); 
    while(q--){
    cin>>ch>>l>>r;
    if(ch=='q')
    cout<<query(tree,1,1,n,l,r)<<'\n';
    else
    updateNode(tree,1,1,n,l,r);
    }    
    
	
}
