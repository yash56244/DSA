int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) 
        return 0;
    int m = matrix[0].size();
    if (m == 0) 
        return 0;
    int count = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1)
                count++;
            else if (matrix[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }
    if (count == 0) 
        return 0;
    int level = 0;
    pair<int, int> p;
    while (!q.empty()) {
        int lno = q.size();
        for (int i = 0; i < lno; i++) {
            p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            // top
            if (x >= 1)
                if (matrix[x - 1][y] == 1) 
                    q.push(make_pair(x - 1, y)), matrix[x - 1][y] = 2;
            // bottom
            if (x < n - 1)
                if (matrix[x + 1][y] == 1) 
                    q.push(make_pair(x + 1, y)), matrix[x + 1][y] = 2;
            // left
            if (y >= 1)
                if (matrix[x][y - 1] == 1) 
                    q.push(make_pair(x, y - 1)), matrix[x][y - 1] = 2;
            // right
            if (y < m - 1)
                if (matrix[x][y + 1] == 1) 
                    q.push(make_pair(x, y + 1)), matrix[x][y + 1] = 2;
        }
        level++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) cnt++;
        }
    }
    if (cnt > 0) 
        return -1;
    else
        return level - 1;
}
