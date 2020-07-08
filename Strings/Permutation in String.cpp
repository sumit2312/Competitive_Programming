// https://leetcode.com/problems/permutation-in-string/

/*
  Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
  In other words, one of the first string's permutations is the substring of the second string.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        if(m>n){
            return false;
        }
        int freq_s1[26];
        int freq_s2[26];
        for(int i=0;i<26;i++) freq_s1[i]=0,freq_s2[i]=0;
        
        for(int i=0;i<m;i++){
            freq_s1[s1[i]-'a']++;
            freq_s2[s2[i]-'a']++;
        }
        for(int i=m;i<n;i++){
            bool flag=true;
            for(int i=0;i<26;i++){
                if(freq_s1[i]!=freq_s2[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return true;
            }
            freq_s2[s2[i-m]-'a']--;
            freq_s2[s2[i]-'a']++;
        }
        bool flag=true;
        for(int i=0;i<26;i++){
            if(freq_s1[i]!=freq_s2[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            return true;
        }
        return false;
    }
};
