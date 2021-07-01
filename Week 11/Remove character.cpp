string removeChars(string string1, string string2) {
    int cnt[26] = {0};
    for(int i = 0; i < string2.length(); i++){
        cnt[string2[i] - 'a']++;
    }
    string ans = "";
    for(int i = 0; i < string1.length(); i++){
        if(cnt[string1[i] - 'a'] == 0){
            ans += string1[i];
        }
    }
    return ans;
}
