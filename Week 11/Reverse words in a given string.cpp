string reverseWords(string S) 
{ 
    int n = S.length();
    int prev = 0;
    for(int i = 0; i < n; i++){
        if(S[i] == '.'){
            reverse(S.begin() + prev, S.begin() + i);
            prev = i + 1;
        }
    }
    reverse(S.begin() + prev, S.end());
    reverse(S.begin(), S.end());
    return S;
} 
