int dp[501][501];
int rec(int arr[], int i, int j){
    if(i + 1 == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k = i + 1; k <= j - 1; k++){
        int cost = rec(arr, i, k);
        cost += rec(arr, k, j);
        cost += arr[i]*arr[j]*arr[k];
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}
int matrixMultiplication(int n, int arr[])
{
    memset(dp, -1, sizeof(dp));
    return rec(arr, 0, n - 1);
}
