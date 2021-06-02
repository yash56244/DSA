bool check(Node *root)
{
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    bool first = true;
    int val;
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
        if(!temp->left && !temp->right){
            if(first){
                val = level;
                first = false;
            }else{
                if(val != level){
                    return false;
                }
            }
        }
    }
    return true;
}
