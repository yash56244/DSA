class Solution {
public:
    int countSegments(string s) {
        int cnt = 1;
        int n = s.length();
        int ii = 0;
        while(s[ii] == ' '){
            ii++;
        }
        if(ii == n)
            return 0;
        for(int i = ii; i < n; i++){
            if(s[i] == ' '){
                cnt++;
                while(s[i] == ' '){
                    i++;
                }
            }
        }
        if(s[n - 1] == ' ')
            cnt--;
        return cnt;
    }
};
