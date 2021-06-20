class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        int m = arr.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(int i = 0; i < m; i++){
            adj[arr[i][1]].push_back(arr[i][0]);
            indegree[arr[i][0]]++;
        }
        vector<int> vis(n);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(!vis[v]){
                    indegree[v]--;
                    if(indegree[v] == 0){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            cnt++;
        }
        return cnt == n;
    }
};
