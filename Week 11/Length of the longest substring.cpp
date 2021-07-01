int longestUniqueSubsttr(string S){
    int n = S.length();
    int last[26];
    memset(last, -1, sizeof(last));
    int i = 0, ans = 0;
    for(int j = 0; j < n; j++){
        i = max(i, last[S[j] - 'a'] + 1);
        ans = max(ans, j - i + 1);
        last[S[j] - 'a'] = j;
    }
    return ans;
}
