class Solution {
public:
    int minDistance(string s1, string s2) {
        int x = s1.length(), y = s2.length();
        int dp[2][y + 1];
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= y; j++){
                if(i == 0 || j == 0){
                    dp[i % 2][j] = 0;
                }
                else if(s1[i - 1] == s2[j - 1]){
                    dp[i % 2][j] = 1 + dp[(i + 1) % 2][j - 1];
                }else{
                    dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return x + y - 2 * dp[x % 2][y];
    }
};
