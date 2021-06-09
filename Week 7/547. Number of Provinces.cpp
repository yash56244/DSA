vector<bool> vis;
void dfs(int i, int n, vector<vector<int>>& adj){
    vis[i] = true;
    for(int j = 0; j < n; j++){
        if(!vis[j] && adj[i][j]){
            dfs(j, n, adj);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vis.assign(n, false);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, n, isConnected);
        }
    }
    return cnt;
}
