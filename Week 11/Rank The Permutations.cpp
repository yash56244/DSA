int rank(string S){
    int fact[16];
    fact[0] = 1;
    for(int i = 1; i <= 15; i++){
        fact[i] = i * fact[i - 1];
        if(fact[i] > mod)
            fact[i] %= mod;
    }
    int n = S.length();
    int rnk = 1;
    int cnt[26] = {0};
    for(int i = 0; i < n; i++){
        cnt[S[i] - 'a']++;
        if(cnt[S[i] - 'a'] > 1){
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        int less = 0;
        for(int j = 0; j < S[i] - 'a'; j++){
            if(cnt[j] > 0){
                less++;
            }
        }
        cnt[S[i] - 'a']--;
        rnk += fact[n - i - 1] * less;
        if(rnk > mod)
            rnk %= mod;
    }
    return rnk;
}
