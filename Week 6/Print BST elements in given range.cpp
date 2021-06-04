void rec(Node* root, int l, int h, vector<int> &ans){
    if(!root){
        return;
    }
    rec(root->left, l, h, ans);
    if(root->data >= l && root->data <= h){
        ans.push_back(root->data);
    }
    rec(root->right, l, h, ans);
}
vector<int> printNearNodes(Node *root, int low, int high)
{
    vector<int> ans;
    rec(root, low, high, ans);
    return ans;
}

