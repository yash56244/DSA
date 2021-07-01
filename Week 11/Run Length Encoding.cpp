string encode(string str)
{     
    string ans = "";
    int n = str.length();
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        ans += str[i];
        ans += to_string(count);
    }
    return ans;
}     
