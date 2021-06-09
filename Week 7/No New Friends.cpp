bool solve(int n, vector<vector<int>>& friends) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < friends.size(); i++) {
        adj[friends[i][0]].push_back(friends[i][1]);
        adj[friends[i][1]].push_back(friends[i][0]);
    }
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 0) {
            return false;
        }
    }
    return true;
}
