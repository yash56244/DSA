
void printLCS(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1];
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int len = dp[x][y];
    char lcs[len + 1];
    lcs[len] = '\0';
    int i = x, j = y;
    while(i > 0 && j > 0){
    	if(s1[i - 1] == s2[j - 1]){
    		lcs[len - 1] = s1[i - 1];
    		len--;
    		i--;
    		j--;
		}
		else if(dp[i - 1][j] > dp[i][j - 1]){
			i--;
		}else{
			j--;
		}
	}
	cout<<lcs;
}
