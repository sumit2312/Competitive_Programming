// https://leetcode.com/problems/combination-sum-iv/

/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long int> dp(target+1);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(auto x:nums){
                if(i-x>=0)
                dp[i]+=dp[i-x];
            }
        }
        return dp[target];
    }
};
