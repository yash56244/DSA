private:
vector<bool> vis;
vector<int> topo;
void dfs(int s, vector<vector<int>> &adj){
    vis[s] = true;
    for(auto v : adj[s]){
        if(!vis[v])
            dfs(v, adj);
    }
    topo.push_back(s);
}
vector<int> topoSort(int V, vector<vector<int>> adj) 
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
public:
string findOrder(string dict[], int n, int k) {
    vector<vector<int>> adj(k);
    for(int i = 0; i < n - 1; i++){
        string w1 = dict[i];
        string w2 = dict[i + 1];
        for(int j = 0; j < min(w1.length(), w2.length()); j++){
            if(w1[j] != w2[j]){
                adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                break;
            }
        }
    }
    vector<int> v = topoSort(k, adj);
    string ans;
    for(int i = 0; i < v.size(); i++){
        ans += v[i] + 'a';
    }
    return ans;
}
