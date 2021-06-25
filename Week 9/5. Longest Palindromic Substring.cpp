class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.length();
        int start = 0, maxLength = 1;
        int high, low;
        for (int i = 1; i < n; ++i) {
            low = i - 1;
            high = i;
            while (low >= 0 && high < n
                   && str[low] == str[high]) {
                if (high - low + 1 > maxLength) {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < n
                   && str[low] == str[high]) {
                if (high - low + 1 > maxLength) {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }
        }
        string s = "";
        for(int i = start; i < start + maxLength; i++){
            s += str[i];
        }
        return s;
    }
};
// another dp approach
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        int mx = 1, st = 0;
        for(int i = 0; i < n - 1; i++){
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if(dp[i][i + 1]){
                st = i;
                mx = 2;
            }
        }
        for(int g = 2; g < n; g++){
            for(int i = 0, j = g; j < n; i++, j++){
                dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
                if(dp[i][j]){
                    st = i;
                    mx = g + 1;
                }
            }
        }
        string ans = "";
        for(int i = st; i < st + mx; i++){
            ans += s[i];
        }
        return ans;
    }
};
