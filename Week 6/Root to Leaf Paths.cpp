vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    queue<pair<Node*, vector<int>>> q;
    q.push({root, {}});
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        Node* temp = f.first;
        vector<int> v = f.second;
        v.push_back(temp->data);
        if(!temp->left && !temp->right){
            ans.push_back(v);
        }
        if(temp->left){
            q.push({temp->left, v});
        }
        if(temp->right){
            q.push({temp->right, v});
        }
    }
    return ans;
}
