int longestSubsequence(int n, int a[])
{
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    return *max_element(dp, dp + n);
}
