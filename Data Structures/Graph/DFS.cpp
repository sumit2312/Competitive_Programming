#include <bits/stdc++.h>
using namespace std;
#define mx 1000
bool vis[mx+1];
vector<long int > v[mx+1];

void DFS(int p)
{
    cout<<p<<endl;
    vis[p]=1;//marking node p as visited.....
    int i,sz=v[p].size();//sz is the number of nodes connected to the node p.....
    for(i=0;i<sz;i++)
    {
        if(vis[v[p][i]]==0)//Checking whether the connected node is visited or not.....
        {
            DFS(v[p][i]);
        }
    }
};

int main()
{
    int n,m;//n is number of nodes in graph and m is number of edges in the graph m=(n-1) from tree.....
    cin>>n>>m;
    int i,a,b;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        //if graph is undirected then.....
        v[a].push_back(b);
        v[b].push_back(a);
        //if graph is directed and there is an edge from a to b.....
        v[a].push_back(b);
    }
    DFS(1);
    return 0;
}
