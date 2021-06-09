vector<int> vis;
void dfs(int s, vector<vector<int>>& adj) {
    vis[s] = true;
    for (auto v : adj[s]) {
        if (!vis[v]) {
            dfs(v, adj);
        }
    }
}
int solve(vector<vector<int>>& friends) {
    int n = friends.size();
    vis.assign(n, false);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, friends);
        }
    }
    return cnt;
}
