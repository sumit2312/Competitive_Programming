#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

const int mod = 1e9+7;

vector<bool> primes(10005,1);
int dis[100005];
bool vis[10005];

int to_num(int a[]){
	int n;
	n = (a[3]*1000)+(a[2]*100)+(a[1]*10)+a[0];
	return n;
}

void to_arr(int a[],int n){
	a[0]=n%10;
	n/=10;
	a[1]=n%10;
	n/=10;
	a[2]=n%10;
	n/=10;
	a[3]=n%10;
}

void seive(){
	int n=10005;
	primes[0]=0;
	//memset(primes,1,sizeof(primes));
	for(int i=2;i*i<n;i++){
		if(primes[i]==1){
			for(int j=2*i;j<n;j+=i){
				primes[j]=0;
			}
		}
	}
}

void solve(){
	int a,b;
	cin>>a>>b;
	if(a==b){
		cout<<0<<"\n";
		return;
	}
	memset(dis,-1,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(a);
	vis[a]=1;
	dis[a]=0;
	int dig[4];
	while(!q.empty()){
		int x=q.front();
		if(x==b){
			break;
		}
		for(int i=0;i<4;i++){
			to_arr(dig,x);
			for(int j=0;j<10;j++){
				dig[i]=j;
				int num=to_num(dig);
				if(!vis[num] && primes[num] && num>1000){
					vis[num]=1;
					q.push(num);
					dis[num]=dis[x]+1;
				}
			}
		}
		q.pop();
	}
	if(dis[b]==-1){
		cout<<-1<<"\n";
	}else{
		cout<<dis[b]<<"\n";
	}
}

signed main(){
	int t;
	cin>>t;
	seive();
	while(t--){
		solve();
	}
}
