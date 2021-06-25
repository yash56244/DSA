class Solution {
public:
    unordered_set<int> s;
    int dp[366];
    vector<int> costs;
    int rec(int i){
        if(i > 365)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        if(s.find(i) != s.end()){
            return dp[i] = min(rec(i + 1) + costs[0], min(rec(i + 7) + costs[1], rec(i + 30) + costs[2]));
        }else{
            return dp[i] = rec(i + 1);
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& _costs) {
        for(auto d : days){
            s.insert(d);
        }
        memset(dp, -1, sizeof(dp));
        costs = _costs;
        return rec(1);
    }
};
