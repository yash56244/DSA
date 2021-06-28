long long maximumAmount(int arr[], int n) 
{
    int dp[n][n];
    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; j < n; ++i, ++j) {
            int x = ((i + 2) <= j)
                        ? dp[i + 2][j]
                        : 0;
            int y = ((i + 1) <= (j - 1))
                        ? dp[i + 1][j - 1]
                        : 0;
            int z = (i <= (j - 2))
                        ? dp[i][j - 2]
                        : 0;
            dp[i][j] = max(
                arr[i] + min(x, y),
                arr[j] + min(y, z));
        }
    }
 
    return dp[0][n - 1];
}
