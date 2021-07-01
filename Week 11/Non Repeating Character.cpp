char nonrepeatingCharacter(string S)
{
    int cnt[26];
    memset(cnt, -1, sizeof(cnt));
    int n = S.length();
    for(int i = 0; i < n; i++){
        if(cnt[S[i] - 'a'] == -1)
            cnt[S[i] - 'a'] = i;
        else
            cnt[S[i] - 'a'] = -2;
    }
    int res = INT_MAX;
    for(int i = 0; i < 26; i++){
        if(cnt[i] >= 0){
            res = min(res, cnt[i]);
        }
    }
    return res == INT_MAX ? '$' : S[res];
}
