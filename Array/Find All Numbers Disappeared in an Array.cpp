/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

*/


/* Idea is to collect each appeared number ans then replace the number at this index to negative value .
   So at last all the numbers which appear has negative value at their indices .
   
   
   e.g. [ 4, 3, 2, 7, 8, 2, 3, 1] we can use a binary array (O(N) space) to count it. [ 1, 1, 1, 1, 0, 0, 1, 1]
  Note that it has the same amount of information with [ -, -, -, -, +, +, -, -] . see? you can just attach these
  information on the original array without generating a new array. That's the whole point.
*/   

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

