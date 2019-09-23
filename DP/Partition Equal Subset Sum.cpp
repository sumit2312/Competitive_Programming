// https://leetcode.com/problems/partition-equal-subset-sum/
//https://www.youtube.com/watch?v=s6FhG--P7z0
/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

*/ 


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        sum = sum>>1;
        vector<vector<bool>> dp(nums.size(),vector<bool>(sum+1,false));
        dp[0][0] = true;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<sum+1;j++){
                if(j>=nums[i]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }else{
                   dp[i][j] = dp[i-1][j]; 
                }                
            }
        }
        return dp[nums.size()-1][sum];        
    }
};
