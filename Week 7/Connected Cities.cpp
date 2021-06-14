void dfs(int s, vector<vector<int>>& adj, vector<bool> &vis, vector<int> &topo){
    vis[s] = true;
    for(auto v : adj[s]){
        if(!vis[v]){
            dfs(v, adj, vis, topo);
        }
    }
    topo.push_back(s);
}
void dfs2(int s, vector<vector<int>> &radj, vector<bool> &vis){
    vis[s] = true;
    for(auto v : radj[s]){
        if(!vis[v]){
            dfs2(v, radj, vis);
        }
    }
}
bool solve(int n, vector<vector<int>>& roads) {
    if(n == 1){
        return true;
    }
    if(roads.size() == 0){
        return false;
    }
    vector<vector<int>> adj(n), radj(n);
    vector<bool> vis;
    vector<int> topo;
    int cnt = 0;
    for(auto r : roads){
        adj[r[0]].push_back(r[1]);
        radj[r[1]].push_back(r[0]);
    }
    vis.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, adj, vis, topo);
        }
    }
    vis.assign(n, false);
    reverse(topo.begin(), topo.end());
    dfs2(topo[0], radj, vis);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            return false;
        }
    }
    return true;
}
