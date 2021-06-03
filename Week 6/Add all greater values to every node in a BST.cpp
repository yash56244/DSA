void rec(Node* root, int* val){
    if(!root){
        return;
    }
    rec(root->right, val);
    *val += root->data;
    root->data = *val;
    rec(root->left, val);
}
Node* modify(Node *root)
{
    int val = 0;
    rec(root, &val);
    return root;
}
