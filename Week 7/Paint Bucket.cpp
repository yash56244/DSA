vector<int> dir{-1, 0, 1, 0, -1};
void dfs(vector<vector<string>>& matrix, int i, int j, string target, string curr) {
    matrix[i][j] = target;
    int n = matrix.size(), m = matrix[0].size();
    for (int k = 0; k < 4; ++k) {
        int x = i + dir[k];
        int y = j + dir[k + 1];
        if (x >= 0 and x < n and y >= 0 and y < m and matrix[x][y] == curr) {
            dfs(matrix, x, y, target, curr);
        }
    }
}
vector<vector<string>> solve(vector<vector<string>>& matrix, int r, int c, string target) {
    if (matrix[r][c] == target) return matrix;
    dfs(matrix, r, c, target, matrix[r][c]);
    return matrix;
}
