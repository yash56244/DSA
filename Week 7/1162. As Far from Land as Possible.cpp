class Solution {
public:
    int maxDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        int cnt1 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    cnt1++;
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        if(cnt1 == 0 || cnt1 == n*m){
            return -1;
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = t.first + dx[i], ny = t.second + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(dist[nx][ny] > dist[t.first][t.second] + 1){
                        dist[nx][ny] = dist[t.first][t.second] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dist[i][j] != INT_MAX)
                    ans = max(ans, dist[i][j]);
            }
        }
        return ans;
    }
};
