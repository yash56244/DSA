vector<vector<int>> adj;
vector<bool> vis;
void dfs(int s){
    vis[s] = true;
    for(auto v : adj[s]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    adj.resize(n);
    for(auto p : connections){
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }
    vis.resize(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    if(cnt - 1 <= connections.size() - (n - cnt)){
        return cnt - 1;
    }else{
        return -1;
    }
}
