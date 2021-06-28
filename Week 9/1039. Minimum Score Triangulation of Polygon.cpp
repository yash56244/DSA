class Solution {
public:
    int dp[51][51];
    int rec(vector<int>& values, int i, int j){
        if(i + 1 == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = i + 1; k <= j - 1; k++){
            ans = min(ans, rec(values, i, k) + rec(values, k, j) + values[i] * values[j] * values[k]);
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp, -1, sizeof(dp));
        int n = values.size();
        return rec(values, 0, n - 1);
    }
};
