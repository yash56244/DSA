int subsetXOR(vector<int> arr, int n, int k) {
    int max_ele = *max_element(arr.begin(), arr.end());
    int m = (1 << (int)(log2(max_ele) + 1) ) - 1;
    if( k > m  )
       return 0;
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i=1; i<=n; i++)
        for (int j=0; j<=m; j++)
            dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]];
    return dp[n][k];
}
