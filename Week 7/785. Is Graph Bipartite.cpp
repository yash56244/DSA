class Solution {
public:
    vector<bool> vis;
    vector<int> color;
    bool dfs(int s, int p, vector<vector<int>>& adj, int clr){
        vis[s] = true;
        color[s] = clr;
        for(auto v : adj[s]){
            if(v != p){
                if(color[v] == color[s]){
                    return false;
                }else if( !vis[v] && !dfs(v, s, adj, 1 - clr)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        color.assign(n, -1);
        vis.assign(n, false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(!dfs(i, -1, adj, 0)){
                    return false;
                }
            }
        }
        return true;
    }
};
