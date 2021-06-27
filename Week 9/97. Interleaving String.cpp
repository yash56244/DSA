class Solution {
public:
    int dp[101][101];
    int rec(string &s1, string &s2, string &s3, int i, int j){
        if(i == s1.length() && j == s2.length() && i + j == s3.length()){
            return dp[i][j] = 1;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i < s1.length() && s1[i] == s3[i + j] && rec(s1, s2, s3, i + 1, j))
            return dp[i][j] = 1;
        if(j < s2.length() && s2[j] == s3[i + j] && rec(s1, s2, s3, i, j + 1))
            return dp[i][j] = 1;
        return dp[i][j] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return rec(s1, s2, s3, 0, 0);
    }
};
