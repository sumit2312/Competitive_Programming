#include <bits/stdc++.h>
using namespace std;

const int MAX=10000;
vector<int> v[MAX];
bool vis[MAX];
int dis[MAX];

void bfs(int s){
	queue<int> q;
	q.push(s);
	vis[s]=true;
	dis[s]=0;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for (int i = 0; i < v[p].size(); ++i)
		{
			if(vis[v[p][i]]==0){
				q.push(v[p][i]);
				vis[v[p][i]]=1;
				dis[v[p][i]]=dis[p]+1;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	bfs(1);
	int q;
	cin>>q;
	int min = INT_MAX;
	int ans;
	while(q--){
		int w;
		cin>>w;
		if(dis[w]<min)
		{
			min = dis[w];
			ans=w;
		}
	}

	cout<<ans<<endl;

	return 0;
}
