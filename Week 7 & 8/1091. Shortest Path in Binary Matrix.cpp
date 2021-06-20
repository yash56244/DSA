class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n == 0 || m == 0)
            return 0;
        if(mat[0][0] != 0)
            return -1;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[] = {0, 0, -1, 1, -1, 1, 1, -1};
        q.push({0, 0});
        dist[0][0] = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            for(int i = 0; i < 8; i++){
                int nx = t.first + dx[i], ny = t.second + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 0){
                    if(dist[nx][ny] > dist[t.first][t.second] + 1){
                        dist[nx][ny] = dist[t.first][t.second] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return dist[n -1][m - 1] == INT_MAX ? -1 : 1+ dist[n -1][m - 1];
    }
};
