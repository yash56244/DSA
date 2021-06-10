bool cycle(int s, vector<vector<int>> &adj, vector<int> &color){
    color[s] = 1;
    for(auto v : adj[s]){
        if(color[v] == 0){
            if(cycle(v, adj, color)){
                return true;
            }
        }else if(color[v] == 1){
            return true;
        }
    }
    color[s] = 2;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> v;
    vector<int> color(V, 0);
    for(int i = 0; i < V; i++){
        if(!cycle(i, graph, color)){
            v.push_back(i);
        }
    }
    return v;
}
