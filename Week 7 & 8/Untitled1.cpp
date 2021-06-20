void dfs(int s, vector<vector<int>> &adj, vector<int> &reach, vector<bool> &vis){
    vis[s] = true;
    reach.push_back(s);
    for(auto v : adj[s]){
        if(!vis[v]){
            dfs(v, adj, reach, vis);
        }
    }
}
vector<vector<int>> solve(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> vis(n, false);
    vector<int> r;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, graph, r, vis);
        }
        for(int i = 0; i < r.size(); i++){
            for(int j = 0; j < r.size(); j++){
                ans[r[i]][r[j]] = 1;
            }
        }
        r.clear();
    }
    return ans;
}
// another solution using union find
void setParent(int i, int key, vector<int> &parent) {
    parent[i] = key;
}

int findParent(int i, vector<int> &parent) {
    if (i == parent[i]) {
        return i;
    }

    return findParent(parent[i], parent);
}
vector<vector<int>> solve(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].size() > 0) {
            for (int j : graph[i]) {
                int left = findParent(i, parent);
                int right = findParent(j, parent);
                if (left != right) {
                    setParent(right, left, parent);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int left = findParent(i, parent);
            int right = findParent(j, parent);
            if (left == right) {
                ans[i][j] = 1;
            }
        }
    }
    return ans;
}
