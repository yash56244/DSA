class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i = 0; i < s.size(); i++)
        {
            if(!st.empty() && st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        string ans = "";
        while(!st.empty())
        {
            ans += (st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// Another inplace approach
class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for (char& c : S)
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);
        return res;
    }
};
