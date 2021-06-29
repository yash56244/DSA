int dp[201][201];
int rec(int n, int k){
    if(k == 0 || k == 1)
        return k;
    if(n == 1)
        return k;
    if(dp[n][k] != -1)
        return dp[n][k];
    int ans = INT_MAX;
    for(int i = 1; i <= k; i++){
        ans = min(ans, max(rec(n - 1, i - 1), rec(n, k - i)));
    }
    return dp[n][k] = 1 + ans;
}
int eggDrop(int n, int k) 
{
    memset(dp, -1, sizeof(dp));
    return rec(n, k);
}
