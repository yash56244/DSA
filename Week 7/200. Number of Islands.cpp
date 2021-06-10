private:
vector<vector<bool>> vis;
int n, m;
public:
void dfs(int i, int j, vector<vector<char>>& grid){
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0' || vis[i][j]){
        return;
    }
    vis[i][j] = true;
    dfs(i + 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
    dfs(i - 1, j, grid);
}
int numIslands(vector<vector<char>>& grid) 
{
    n = grid.size();
    m = grid[0].size();
    vis.resize(n);
    for(int i = 0; i < n; i++){
        vis[i].resize(m);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == '1'){
                dfs(i, j, grid);
                cnt++;
            }
        }
    }
    return cnt;
}
