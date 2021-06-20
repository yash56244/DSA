class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        int m = arr.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0), ans;
        for(int i = 0; i < m; i++){
            adj[arr[i][1]].push_back(arr[i][0]);
            indeg[arr[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(auto u : adj[v]){
                indeg[u]--;
                if(indeg[u] == 0){
                    q.push(u);
                }
            }
            cnt++;
        }
        if(cnt == n){
            return ans;
        }else{
            return {};
        }
    }
};
