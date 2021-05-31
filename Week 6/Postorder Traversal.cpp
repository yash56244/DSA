vector<int> v;
void rec(Node* root){
    if(root != NULL){
        rec(root->left);
        rec(root->right);
        v.push_back(root->data);
    }
}
vector <int> postOrder(Node* root)
{
    v.clear();
    rec(root);
    return v;
}
