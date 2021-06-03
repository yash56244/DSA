int size(Node* root){
    if(!root){
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
    bool isCompleteBT(Node* root){
        int h = size(root);
        queue<Node*> q;
        q.push(root);
        h--;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    h--;
                }
                if(temp->right){
                    q.push(temp->right);
                    h--;
                }
                if(temp->right && !temp->left){
                    return false;
                }else if(temp->left && !temp->right && h != 0){
                    return false;
                }
            }
        }
        return true;
    }

