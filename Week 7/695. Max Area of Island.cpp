private:
vector<vector<bool>> vis;
int n, m, cnt;
public:
void dfs(int i, int j, vector<vector<int>>& grid){
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j]){
        return;
    }
    cnt++;
    vis[i][j] = true;
    dfs(i + 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
    dfs(i - 1, j, grid);
}
int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    n = grid.size();
    m = grid[0].size();
    vis.resize(n);
    for(int i = 0; i < n; i++){
        vis[i].resize(m);
    }
    int mcnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j]){
                cnt = 0;
                dfs(i, j, grid);
                mcnt = max(cnt, mcnt);
            }
        }
    }
    return mcnt;
}
