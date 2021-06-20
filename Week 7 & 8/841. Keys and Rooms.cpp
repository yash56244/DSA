vector<bool> vis;
void dfs(vector<vector<int>> &adj, int s){
    vis[s] = true;
    for(auto v : adj[s]){
        if(!vis[v]){
            dfs(adj, v);
        }
    }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vis.resize(n);
    dfs(rooms, 0);
    for(int i = 0; i< n;i++){
        if(!vis[i]){
            return false;
        }
    }
    return true;
}
