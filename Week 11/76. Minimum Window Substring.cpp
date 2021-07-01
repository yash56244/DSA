class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        int n1 = s.length(), n2 = t.length();
        for(int i = 0; i < n2; i++){
            mp2[t[i]]++;
        }
        int i = -1, j = -1, mcnt = 0;
        string ans = "";
        while(true){
            bool f1 = false, f2 = false;
            while(i < n1 - 1 && mcnt < n2){
                i++;
                char c = s[i];
                mp1[c]++;
                if(mp1[c] <= mp2[c]){
                    mcnt++;
                }
                f1 = true;
            }
            while(j < i && mcnt == n2){
                string pans = s.substr(j + 1, i - j);
                if(ans.length() == 0 || ans.length() > pans.length()){
                    ans = pans;
                }
                j++;
                char c = s[j];
                mp1[c]--;
                if(mp1[c] < mp2[c]){
                    mcnt--;
                }
                f2 = true;
            }
            if(!f1 && !f2)
                break;
        }
        return ans;
    }
};
