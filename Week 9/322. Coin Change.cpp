class Solution {
public:
    int coinChange(vector<int>& S, int m) {
        vector<long> dp(m + 1, INT_MAX);
        int n = S.size();
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = S[i]; j <= m; j++){
                dp[j] = min(dp[j], 1 + dp[j - S[i]]);
            }
        }
        return dp[m] == INT_MAX ? -1 : dp[m];
    }
};
