class Solution {
public:
    vector<pair<int, int>> v;
    int dp[601][101][101];
    int rec(int i, int m, int n){
        if(i < 0 || (m <= 0 && n <= 0))
            return 0;
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        int ans;
        if(m < v[i].first || n < v[i].second)
            ans = rec(i - 1, m, n);
        else
            ans = max(rec(i - 1, m, n), 1 + rec(i - 1, m - v[i].first, n - v[i].second));
        return dp[i][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        int k = strs.size();
        for(int i = 0; i < k; i++){
            int nn = strs[i].length();
            int cnt0 = 0, cnt1 = 0;
            for(int j = 0; j < nn; j++){
                if(strs[i][j] == '1')
                    cnt1++;
                else
                    cnt0++;
            }
            v.push_back({cnt0, cnt1});
        }
        return rec(k - 1, m, n);
    }
};
