vector<int> iterativeDFS(int s){
	vector<bool> vis(n, false);
	stack<int> s;
	vector<int> v;
	s.push(s);
	while(!s.empty()){
		int u = s.top();
		s.pop();
		if(!vis[u]){
			v.push_back(u);
			vis[u] = true;
		}
		for(auto v : adj[u]){
			if(!vis[v]){
				s.push(v);
			}
		}
	}
	return v;
}
