int knapSack(int n, int w, int val[], int wt[])
{
    vector<int> dp(w + 1, 0);
    for(int i = 1; i <= w; i++){
        for(int j = 0; j < n; j++){
            if(i >= wt[j]){
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
            }
        }
    }
    return dp[w];
}
