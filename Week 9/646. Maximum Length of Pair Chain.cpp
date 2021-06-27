class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(), p.end());
        int dp[n];
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(p[j][1] < p[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp, dp+n);
    }
};
