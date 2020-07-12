// https://leetcode.com/problems/reconstruct-itinerary/

/* The assumption for this to work is there is guaranteed to exist one Euler path. (This problem is basically to find a Euler path of a graph). */

class Solution {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++){
            graph[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string> res;
        dfs("JFK",res);
        reverse(res.begin(),res.end());
        return res;
    }
    void dfs(string u,vector<string> &res){
        
        while (!graph[u].empty())
        {
            string to_vtex = graph[u].top();
            graph[u].pop();
            dfs(to_vtex,res);
        }
        res.push_back(u);
    }
};
