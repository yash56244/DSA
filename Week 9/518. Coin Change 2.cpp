class Solution {
public:
    int change(int n, vector<int>& s) {
        int m = s.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = s[i]; j <= n; j++){
                dp[j] += dp[j - s[i]];
            }
        }
        return dp[n];
    }
};
