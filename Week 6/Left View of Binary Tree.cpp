vector<int> leftView(Node *root)
{
    if(root == NULL){
        return {};
    }
    queue<Node*> q;
    q.push(root);
    Node* prev = NULL;
    q.push(NULL);
    vector<int> ans;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(prev == NULL && temp){
            ans.push_back(temp->data);
        }
        prev = temp;
        if(temp != NULL){
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
    return ans;
}
