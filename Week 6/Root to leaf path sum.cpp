bool hasPathSum(Node *root, int S) {
    vector<int> ans;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        Node* temp = f.first;
        int v = f.second;
        v += temp->data;
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
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == S){
            return true;
        }
    }
    return false;
}
