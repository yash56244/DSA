class Solution {
public:
    int n;
    pair<int, int> n2c(int no){
        int x = no / n;
        x = n - x - 1;
        if(no % n == 0)
            x++;
        int y;
        if((no / n) & 1){
            y = n - (no % n);
            if((no % n) == 0)
                y--;
        }
        else{
            y = (no % n) - 1;
            if(y == -1)
                y++;
        }
        return {x, y};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push(1);
        vis[n2c(1).first][n2c(1).second] = true;
        // for(int i = 1; i <= 36; i++){
        //     cout<<i << " "<<n2c(i).first<<" "<<n2c(i).second<<endl;
        // }
        int level = 0;
        while(!q.empty()){
            int nn = q.size();
            for(int j = 0; j < nn; j++){
                int t = q.front();
                if(t == n*n)
                    return level;
                q.pop();
                for(int i = t + 1; i <= min(t + 6, n*n); i++){
                    auto p = n2c(i);
                    if(!vis[p.first][p.second]){
                        vis[p.first][p.second] = true;
                        if(board[p.first][p.second] != -1)
                            q.push(board[p.first][p.second]);
                        else
                            q.push(i);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
