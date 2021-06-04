int rec(Node* root){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        int data = root->data;
        root->data = 0;
        return data;
    }
    int data = root->data;
    root->data = rec(root->left) + rec(root->right);
    return root->data + data;
}
void toSumTree(Node *node)
{
    rec(node);
}
