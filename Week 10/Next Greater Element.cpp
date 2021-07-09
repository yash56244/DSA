vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack<long long> s;
    vector<long long> ans;
    s.push(arr[n - 1]);
    ans.push_back(-1);
    for(int i = n - 2; i >= 0; i--){
        while(!s.empty() && arr[i] > s.top()){
            s.pop();
        }
        if(!s.empty())
            ans.push_back(s.top());
        else
            ans.push_back(-1);
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
