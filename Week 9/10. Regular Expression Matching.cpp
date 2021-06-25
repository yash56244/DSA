class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool dp[n + 1][m + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }else if(i == 0){
                    dp[i][j] = false;
                }else if(j == 0){
                    char c = p[i - 1];
                    if(c == '*'){
                        dp[i][j] = dp[i - 2][j];
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    char cp = p[i - 1], cs = s[j - 1];
                    if(cp == '*'){
                        dp[i][j] = dp[i - 2][j];
                        char cpp = p[i - 2];
                        if(cpp == '.' || cpp == cs){
                            dp[i][j] = dp[i][j] || dp[i][j - 1];
                        }
                    }else if(cp == '.' || cp == cs){
                        dp[i][j] = dp[i - 1][j - 1];
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[n][m];
    }
};
