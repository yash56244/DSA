class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> ans;
        s.push(n - 1);
        ans.push_back(0);
        for(int i = n - 2; i >= 0; i--){
            while(!s.empty() && arr[i] >= arr[s.top()]){
                s.pop();
            }
            if(!s.empty())
                ans.push_back(s.top() - i);
            else
                ans.push_back(0);
            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
