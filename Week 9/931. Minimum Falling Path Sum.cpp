class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int dp[n][n];
        for(int j = 0; j < n; j++)
            dp[n - 1][j] = mat[n - 1][j];
        for(int i = n - 2; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(j == n - 1)
                    dp[i][j] = mat[i][j] + min(dp[i + 1][j - 1], dp[i + 1][j]);
                else if(j == 0)
                    dp[i][j] = mat[i][j] + min(dp[i + 1][j + 1], dp[i + 1][j]);
                else
                    dp[i][j] = mat[i][j] + min(dp[i + 1][j], min(dp[i + 1][j - 1], dp[i + 1][j + 1]));
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j < n; j++)
            ans = min(ans, dp[0][j]);
        return ans;
    }
};
