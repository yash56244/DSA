int getMaxWidth(Node* root)
    {
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        map<int, int> m;
        while(!q.empty()){
            auto p = q.front();
            Node* temp = p.first;
            int h = p.second;
            q.pop();
            m[h]++;
            if(temp->right){
                q.push({temp->right, h + 1});
            }
            if(temp->left){
                q.push({temp->left, h + 1});
            }
        }
        int ans = 0;
        for(auto e : m){
            ans = max(ans, e.second);
        }
        return ans;
    }
