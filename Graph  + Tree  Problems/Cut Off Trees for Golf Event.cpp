// https://leetcode.com/problems/cut-off-trees-for-golf-event/

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest.size()==0 || forest[0].size()==0) return 0;
        int n = forest.size();
        int m = forest[0].size();
        vector<vector<int>> nodes;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1)
                    nodes.push_back({forest[i][j],i,j});
            }
        }
        sort(nodes.begin(),nodes.end());
        int a=0,b=0;
        int ans=0;
        
        for(int i=0;i<nodes.size();i++){
            int curr = bfs(forest,a,b,nodes[i][1],nodes[i][2]);
            
            if(curr==-1) return -1;
            ans+=curr;
            a=nodes[i][1];
            b=nodes[i][2];
        }
        return ans;
    }
private:
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    int bfs(vector<vector<int>>& forest,int a,int b,int x,int y){
        if(a==x && b==y) return 0;
        queue<pair<int,int>> q;
        int steps=0;
        int n = forest.size(),m = forest[0].size();
        q.push({a,b});
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                pair<int,int> tp = q.front();q.pop();
                int X = tp.first;
                int Y = tp.second;
                
                if(x==X && y==Y) return steps;
                for(int i=0;i<4;i++){
                    int xx = X+dir[i];
                    int yy = Y+dir[i+1];
                    if(xx>=0 && xx<n && yy>=0 && yy<m && forest[xx][yy]!=0 && !vis[xx][yy]){
                        q.push({xx,yy});
                        vis[xx][yy]=1;
                    }
                }    
            } 
            steps++;
        }
        return -1;        
    }
};
