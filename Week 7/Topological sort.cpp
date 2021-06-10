vector<bool> vis;
vector<int> topo;
void dfs(int s, vector<int> adj[]){
    vis[s] = true;
    for(auto v : adj[s]){
        if(!vis[v])
            dfs(v, adj);
    }
    topo.push_back(s);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vis.resize(V);
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, adj);
        }
    }
    reverse(topo.begin(), topo.end());
    return topo;
}
