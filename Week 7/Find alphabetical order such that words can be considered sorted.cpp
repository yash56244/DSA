void findOrder(vector<string> &v){
	int n = v.size();
	if(n == 1){
		cout<<"abcdefghijklmnopqrstuvwxyz";
		return;
	}
	vector<int> adj[26];
	vector<int> indeg(26, 0);
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < min(v[i].length(), v[i+1].length); j++){
			if(v[i][j] != v[i+1][j]){
				adj[v[i][j] - 'a'].push_back(v[i+1][j] - 'a');
				indeg[v[i+1][j]]++;
				break;
			}
		}
		if(v[i].length() > v[i+1].length()){
			cout<<"Impossible";
			return;
		}
	}
	queue<int> q;
	for(int i = 0; i < 26; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}
	int cnt = 0;
	vector<char> ans;
	while!q.empty(){
		int u = q.front();
		q.pop();
		ans.push_back(u + 'a');
		for(auto v : adj[u]){
			indeg[v]--;
			if(indeg[v] == 0){
				q.push(v);
			}
		}
		cnt++;
	}
	if(cnt != 26){
		cout<<"Impossible";
		return;
	}
	for(auto c : ans){
		cout<<c;
	}
}
