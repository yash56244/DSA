int maximumPath(int n, vector<vector<int>> mat)
{
    int dp[n][n];
    for(int j = 0; j < n; j++)
        dp[n - 1][j] = mat[n - 1][j];
    for(int i = n - 2; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(j == n - 1)
                dp[i][j] = mat[i][j] + max(dp[i + 1][j - 1], dp[i + 1][j]);
            else if(j == 0)
                dp[i][j] = mat[i][j] + max(dp[i + 1][j + 1], dp[i + 1][j]);
            else
                dp[i][j] = mat[i][j] + max(dp[i + 1][j], max(dp[i + 1][j - 1], dp[i + 1][j + 1]));
        }
    }
    int ans = 0;
    for(int j = 0; j < n; j++)
        ans = max(ans, dp[0][j]);
    return ans;
}
