class Solution {
public:
    int rec(string s){
        if(s.length() == 1 && s[0] == '1'){
            return 0;
        }
        if(s[s.length() - 1] == '1'){
            int i = s.length() - 1;
            while(i >= 0 && s[i] == '1'){
                i--;
            }
            string ss = "";
            if(i == -1){
                ss += '1';
                for(int k = 0; k < s.length(); k++){
                    ss += '0';
                }
                return 1 + rec(ss);
            }
            s[i] = '1';
            for(int k = i + 1; k < s.length(); k++){
                s[k] = '0';
            }
            return 1 + rec(s);
        }else{
            return 1 + rec(s.substr(0, s.length() - 1));
        }
    }
    int numSteps(string s) {
        return rec(s);
    }
};
// Iterative
int numSteps(string s) {
    int step = 0;
    while (s != "1") {
        if (s.back() == '0') s.pop_back();
        else {
            while (!s.empty() && s.back() == '1') {
                s.pop_back();
                step++;
            }
            if (s.empty()) return step + 1;
            else s.back() = '1';
        }
        step++;
    }
    return step;
}
