vector<int> Kdistance(struct Node *root, int k)
{
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    vector<int> res;
    while(!q.empty()){
        Node* temp = q.front().first;
        int level = q.front().second;
        q.pop();
        if(temp->left){
            q.push({temp->left, level + 1});
        }
        if(temp->right){
            q.push({temp->right, level + 1});
        }
        if(level == k){
            res.push_back(temp->data);
        }
    }
    return res;
}
