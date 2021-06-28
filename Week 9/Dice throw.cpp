long long dp[51][51];
long long rec(int m, int n, int x){
	if(x == 0 && n == 0)
		return 1;
	if(n > x || n <= 0 || x <= 0)
		return 0;
	if(dp[n][x] != - 1)
		return dp[n][x];
	long long ways = 0;
	for(int i = 1; i <= m; i++){
		ways += rec(m, n - 1, x - i);
	}
	return dp[n][x] = ways;
}
long long noOfWays(int M , int N , int X) {
    memset(dp, -1, sizeof(dp));
    return rec(M, N, X);
}
