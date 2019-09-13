class Solution {
public:
    int change(int t, vector<int>& cs) {
        int dp[t + 1] = { 1 };
        for (auto c : cs)
            for (auto j = c; j <= t; ++j) dp[j] += dp[j - c];
    return dp[t];
    }
};
