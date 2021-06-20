class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        for(int i = 0; i < n - 1; i++){
            for(auto p : times){
                if(dist[p[0]] != INT_MAX && dist[p[1]] > dist[p[0]] + p[2]){
                    dist[p[1]] = dist[p[0]] + p[2];
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
