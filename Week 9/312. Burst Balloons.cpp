class Solution {
public:
    int dp[503][503];
    int rec(vector<int>& values, int i, int j){
        if(i + 1 == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        for(int k = i + 1; k <= j - 1; k++){
            ans = max(ans, rec(values, i, k) + rec(values, k, j) + values[i] * values[j] * values[k]);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        vector<int> arr(n + 2);
        arr[0] = 1;
        for(int i = 1; i <= n; i++)
            arr[i] = nums[i - 1];
        arr[n + 1] = 1;
        return rec(arr, 0, n + 1);
    }
};
