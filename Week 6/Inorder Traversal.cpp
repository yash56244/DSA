vector<int> v;
void rec(Node* root){
    if(root != NULL){
        rec(root->left);
        v.push_back(root->data);
        rec(root->right);
    }
}
vector<int> inOrder(Node* root)
{
    rec(root);
    return v;
}
