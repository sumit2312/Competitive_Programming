// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int n=S.size();
        int m=T.size();
        int cnt1=0,cnt2=0;
        int i=n-1,j=m-1;
        while(i>=0 || j>=0){
            while(i>=0){
                if(S[i]=='#') {cnt1++,i--;}
                else if(cnt1>0) {cnt1--,i--;}
                else break;
            }
            while(j>=0){
                if(T[j]=='#') {cnt2++,j--;}
                else if(cnt2>0) {cnt2--,j--;}
                else break;
            }
            if(i>=0 && j>=0 && S[i]!=T[j]){
                return false;
            }
            cnt1=0;cnt2=0;
            if ((i >= 0) != (j >= 0))
                return false;
            i--;j--;
        }
        return true;
    }
};
