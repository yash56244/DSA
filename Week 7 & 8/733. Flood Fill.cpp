bool isSafe(int i, int j, int n, int m){
    if(i < 0 || j < 0 || i > n - 1 || j > m - 1){
        return false;
    }
    return true;
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> vis(n);
    for(int i = 0; i < n; i++){
        vis[i].resize(m);
    }
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int icolor = image[sr][sc];
    vis[sr][sc] = true;
    image[sr][sc] = newColor;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for(int i = 0; i < 4; i++){
            if(isSafe(x + dx[i], y + dy[i], n, m) && image[x + dx[i]][y + dy[i]] == icolor && !vis[x + dx[i]][y + dy[i]]){
                q.push({x + dx[i], y + dy[i]});
                vis[x + dx[i]][y + dy[i]] = true;
                image[x + dx[i]][y + dy[i]] = newColor;
            }
        }
    }
    return image;
}
