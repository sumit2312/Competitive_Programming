/*Traverse the array from front to end, let a variable cur increase by 1 if we encounter 1, decrease by 1 
if we encounter 0. Use an hash table (unordered_map in C++) to record the first index for each values of cur.
In each iteration, we look up the hash table for the first index at which cur has the same value. Output the 
maximum index difference.*/

/*Here's an O(n)-time, O(n)-space algorithm. I'm not sure it's optimal, but it beats quadratic time.

The basic idea is the following. Suppose that you scan from the left of the array to the right recording, at each step,
the difference between the number of 1s and the number of 0s. If you write these values out at each step, you'll get 
something like this:

  1,   0,   1,    0,    0,   0,   0
0,   1,   0,   1,    0,    -1,  -2,  -3
If you have a sub array with the same number of 0s and 1s, then the net difference of 0s and 1s at the start of the
subarray will equal the net number after the subarray. Therefore, this problem can be reframed as trying to find two
equal values in the auxiliary array that are equal and as far apart as possible.

The good news is that every entry in the array is between -n and +n, so you can make a 2n+1 element table and store 
in it the indices of the first and last time each number appears. From there, it's easy to find the longest range. 
Overall, this needs O(n) space and everything can be populated and searched in O(n) time.
*/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int ans = 0, cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i] ? 1 : -1;
            if (m.count(cur))
                ans = max(ans, i - m[cur]);
            else
                m[cur] = i;
        }
        return ans;
    }
};
