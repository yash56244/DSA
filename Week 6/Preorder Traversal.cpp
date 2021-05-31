vector<int> v;
void rec(Node* root){
    if(root != NULL){
        v.push_back(root->data);
        rec(root->left);
        rec(root->right);
    }
}
vector<int> preorder(Node* root)
{
    v.clear();
    rec(root);
    return v;
}
