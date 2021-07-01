typedef long long int ll;
const ll mod = 1e9 + 7;
class Solution {
public:
    ll dp[1001][1001];
    ll rec(int n, int k){
        if(k == 0 || k > n){
            return 0;
        }
        if(n <= 2)
            return 1;
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        ll ans = rec(n - 1, k - 1) % mod;
        ans += ((n - 1) % mod) * rec(n - 1, k) % mod;
        return dp[n][k] = ans % mod;
    }
    int rearrangeSticks(int n, int k) {
        memset(dp, -1, sizeof(dp));
        rec(n, k);
        return dp[n][k];
    }
};
