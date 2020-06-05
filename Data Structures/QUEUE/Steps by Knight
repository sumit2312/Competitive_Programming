// https://practice.geeksforgeeks.org/problems/steps-by-knight/0

// Author - sumit_011

#include<bits/stdc++.h>
using namespace std;
 
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2}; 
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};  
 
void solve(){
    int n;
    cin>>n;
    bool vis[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            vis[i][j]=false;
        }
    }
    int a,b;
    int x,y;
    cin>>a>>b>>x>>y;
    queue<pair<pair<int,int>,int>> q;
    q.push({{a,b},0});
    int cnt=0;
    while(!q.empty()){
        pair<pair<int,int>,int> p = q.front();
        q.pop();
        if(p.first.first==x && p.first.second==y){
            cout<<p.second<<"\n";
            return;
        }
        for(int i=0;i<8;i++){
            int new_x = p.first.first + dx[i];
            int new_y = p.first.second + dy[i];
            if(new_x>=1 && new_x<=n && new_y>=1 && new_y<=n && !vis[new_x][new_y]){
                vis[new_x][new_y]=true;
                q.push({{new_x,new_y},p.second+1});
            }
        }
    }
    cout<<cnt<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}
