/*
Given an array of n positive integers, your task is to count the number of subarrays having sum x.

Input

The first input line has two integers n and x: the size of the array and the target sum x.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

Constraints
1≤n≤2⋅105
1≤x,ai≤109
Example

Input:
5 7
2 4 1 2 7

Output:
3

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
	int n,x;
	cin>>n>>x;
	int a[n];
	rep(i,0,n) cin>>a[i];
	unordered_map<int,int> m;
	int res=0;
	int sum=0;
	rep(i,0,n){
		sum+=a[i];
		if(sum==x) res++;
		if(m.find(sum-x)!=m.end()){
			res+=(m[sum-x]);
		}
		m[sum]++;
	}
	
	cout<<res<<"\n";
}


int32_t main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
