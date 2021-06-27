int knapSack(int W, int wt[], int val[], int n) 
{ 
    int dp[2][W + 1]; 
    for (int i = 0; i <= n; i++)  
    { 
        for (int w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                dp[i % 2][w] = 0; 
            else if (wt[i - 1] <= w) 
                dp[i % 2][w] = max(val[i - 1] 
                          + dp[(i + 1) % 2][w - wt[i - 1]], 
                          dp[(i + 1) % 2][w]); 
            else
                dp[i % 2][w] = dp[(i + 1) % 2][w]; 
        } 
    } 
  
    return dp[n % 2][W]; 
}
