#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
int arr[1000];

int DFS(int j)
{
	// cout<<j;
	int maxm=arr[j];
	for (int i = 0; i < graph[j].size(); ++i)
		maxm=max(maxm,DFS(graph[j][i]));		
	
	return maxm;
}

int main(){
	int N;
	int E;	
	cin>>N>>E;

	int a,b;
	for (int i = 0; i < E; ++i)
	{
		cin>>a>>b;
		graph[a].push_back(b);
	}
	for (int i = 1; i < N+1; ++i)
	{
		cin>>arr[i];
	}
	cout<<DFS(1);

	return 0;
}
