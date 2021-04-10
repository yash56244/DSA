ll FindMaxSum(ll arr[], ll n)
{
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = arr[0];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
    }
    return dp[n];
}
