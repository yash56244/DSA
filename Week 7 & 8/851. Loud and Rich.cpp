vector<vector<int>> adj;
vector<int> ans;
void dfs(int s, vector<int> &arr){
    if(ans[s] == -1){
        ans[s] = s;
        for(auto v : adj[s]){
            dfs(v, arr);
            if(arr[ans[v]] < arr[ans[s]]){
                ans[s] = ans[v];
            }
        }   
    }
}
vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int m = richer.size();
    int n = quiet.size();
    adj.resize(n);
    for(int i = 0; i < m; i++){
        adj[richer[i][1]].push_back(richer[i][0]);
    }
    ans.assign(n, -1);
    for(int i = 0; i < n; i++){
        dfs(i, quiet);
    }
    return ans;
}
