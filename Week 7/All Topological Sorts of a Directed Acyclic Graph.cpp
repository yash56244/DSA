void alltopologicalSort(vector<int> &order, vector<int> &vis){
	bool completed = true;
	for(int i = 0; i < n; i++){
		if(inDegree[i] == 0 && !vis[i]){
			vis[i] = true;
			for(auto v : adj[i]){
				inDegree[v]--;
			}
			order.push_back(i);
			alltopologicalSort(order, vis);
			vis[i] = false;
			for(auto v : adj[i]){
				inDegree[v]++;
			}
			order.pop_back();
			completed = false;
		}
	}
	if(completed){
		for(int i = 0; i < order.size(); i++){
			cout<<order[i]<<" ";
		}
	}
}
