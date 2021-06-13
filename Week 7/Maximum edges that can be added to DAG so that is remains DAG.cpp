vector<int> findOrder(int n, vector<vector<int>>& adj, vector<int> &indeg) {
    vector<int> ans;
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for(auto u : adj[v]){
            indeg[u]--;
            if(indeg[u] == 0){
                q.push(u);
            }
        }
        cnt++;
    }
    if(cnt == n){
        return ans;
    }else{
        return {};
    }
}
void maximumEdgeAddtion(int n, vector<vector<int>>& adj, vector<int> &indeg){
	vector<bool> vis(n, false);
	vector<int> topo = findOrder(n, adj, indeg);
	for(int i = 0; i < n; i++){
		for(auto v : adj[topo[i]]){
			vis[v] = true;
		}
		for(int j = i + 1; j < n; j++){
			if(!vis[topo[j]]){
				cout<<topo[i]<<"->"<<topo[j];
			}
			vis[topo[j]] = false;
		}
	}
}
