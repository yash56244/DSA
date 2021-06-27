int noOfLis(int n, int a[])
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
    int cnt = 0;
    int mx = *max_element(dp, dp + n);
    for(int i = 0; i < n; i++){
    	if(mx == dp[i])
    		cnt++;
	}
    return cnt;
}
