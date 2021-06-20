void dfs(int s, vector<vector<int>> &adj, vector<bool> &vis){
    vis[s] = true;
    for(auto v : adj[s]){
        if(!vis[v]){
            dfs(v, adj, vis);
        }
    }
}
float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}
int solve(vector<vector<int>>& points, int k) {
    int n = points.size();
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                if(distance(points[i][0], points[i][1], points[j][0], points[j][1]) <= k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    int cnt = 0;
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, adj, vis);
            cnt++;
        }
    }
    return cnt;
}
