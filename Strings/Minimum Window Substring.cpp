// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> remaining(128,0);
        for(auto x:t) remaining[x]++;
        if(s.size()<t.size()){
            return "";
        }
        int req=t.size();
        int i=0,j=0;
        int left=0;
        int mn=INT_MAX;
        while(i<=s.size()){
            if(req>0){
                remaining[s[i]]--;
                if(remaining[s[i]] >=0)
                    req--;
                i++;
            }else{
                if(i-j<mn){
                    mn=i-j;
                    left=j;
                }
                remaining[s[j]]++;
                if(remaining[s[j]] > 0)
                    req++;
                j++;                
            }
        }
        if(mn==INT_MAX){
            return "";
        }else{
            return s.substr(left,mn);
        }
        
    }
};
