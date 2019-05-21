class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        int mx_area =0;
        int tp;
        int area =0;
        int i=0;
        while(i<n){
            if(s.empty() || a[s.top()]<=a[i]){
                s.push(i++);
            }else{
                tp = s.top();
                s.pop();
                area = a[tp] * ( s.empty() ? i : i-s.top()-1);
                
                if(mx_area < area){
                    mx_area = area;
                }
            }
        }
        while(!s.empty()){
            tp = s.top();
                s.pop();
                area = a[tp] * ( s.empty() ? i : i-s.top()-1);
                
                if(mx_area < area){
                    mx_area = area;
                }
            
        }
        return mx_area;
    }
};
