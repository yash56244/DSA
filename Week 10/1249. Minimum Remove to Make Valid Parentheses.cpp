class Solution {
public:
    bool match(char a, char b){
        if(a == '{' && b == '}'){
            return true;
        }
        if(a == '(' && b == ')'){
            return true;
        }
        if(a == '[' && b == ']'){
            return true;
        }
        return false;
    }
    string minRemoveToMakeValid(string x) {
        stack<pair<char, int>> s;
        for(int i = 0; i < x.length(); i++){
            if(!s.empty()){
                if(match(s.top().first, x[i])){
                    s.pop();
                    continue;
                }
            }
            if(!(x[i] >= 'a' && x[i] <= 'z'))
                s.push({x[i], i});
        }
        vector<bool> vis(x.length(), false);
        while(!s.empty()){
            vis[s.top().second] = true;
            s.pop();
        }
        string ans = "";
        for(int i = 0; i < x.length(); i++){
            if(!vis[i]){
                ans +=x[i];
            }
        }
        return ans;
    }
};
