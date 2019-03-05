#include <bits/stdc++.h>
using namespace std;
#define mx 1000
bool vis[mx+1];
vector<long int > v[mx+1];

//BFS is a level order traversal from the starting node.which means that the nodes will
//be visited according to the minimum number of nodes that connects the current node to
//the starting node.....

void BFS(int p)
{
    int i,sz;
    queue<long int > q;
    q.push(p);
    vis[p]=1;
    while(!q.empty())
    {
        p=q.front();//getting the front
        q.pop();
        cout<<p<<endl;
        sz=v[p].size();
        for(i=0;i<sz;i++)
        {
            if(vis[v[p][i]]==0)//if the node is not visited pushing that in the queue.....
            {
                vis[v[p][i]]=1;//marking the node as it is going to be visited.....
                q.push(v[p][i]);
            }
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
        //v[a].push_back(b);
    }
    BFS(1);
    return 0;
}
