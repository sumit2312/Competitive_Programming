// https://practice.geeksforgeeks.org/problems/rotten-oranges/0

#include<bits/stdc++.h>
using namespace std;

const int N=105;


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                if(arr[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        //cout<<q.size()<<"\n";
        while(!q.empty()){
            int sz = q.size();
            //cout<<sz<<"\n";
            for(int i=0;i<sz;i++){
                pair<int,int> p = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x = p.first + dx[k];
                    int y = p.second + dy[k];
                    //cout<<x<<" "<<y<<"\n";
                    if(x>=0 && x<n && y>=0 && y<m && arr[x][y]==1){
                        arr[x][y]=2;
                        q.push({x,y});
                        
                    }
                }
            }
            cnt++;
        }
        //cout<<endl;
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1 && flag==false){
					flag = true;
					cout<<-1<<"\n";
				}
            }
            //cout<<endl;
            if(flag){
                break;
            }
        }
        if(!flag)
        cout<<cnt-1<<"\n";
    }
    return 0;
}
