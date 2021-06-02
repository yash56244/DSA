vector <int> verticalSum(Node *root) {
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        vector<int> ans;
        while(!q.empty()){
            Node* temp = q.front().first;
            int vl = q.front().second;
            q.pop();
            m[vl] += (temp->data);
            if(temp->left){
                q.push({temp->left, vl - 1});
            }
            if(temp->right){
                q.push({temp->right, vl + 1});
            }
        }
        for(auto e : m){
            ans.push_back(e.second);
        }
        return ans;
    }
