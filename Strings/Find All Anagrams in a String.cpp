// problem link - https://leetcode.com/problems/find-all-anagrams-in-a-string/ 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n=s.length();
        int m=p.length();
        if(m>n){
            return res;
        }
        int freq_s[26];
        int freq_p[26];
        for(int i=0;i<26;i++) freq_s[i]=0,freq_p[i]=0;
        for(int i=0;i<m;i++){
            freq_p[p[i]-'a']++;
            freq_s[s[i]-'a']++;
        }
        // a b c d e 
        // b c a h g
        for(int i=m;i<n;i++){
            bool flag=true;
            for(int i=0;i<26;i++){
                if(freq_s[i]!=freq_p[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                res.push_back(i-m);
            }
            freq_s[s[i-m]-'a']--;
            freq_s[s[i]-'a']++;
        }
        bool flag=true;
        for(int i=0;i<26;i++){
            if(freq_s[i]!=freq_p[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            res.push_back(n-m);
        }
        return res;
        
    }
};
