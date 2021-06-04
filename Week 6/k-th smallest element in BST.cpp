int KthSmallestElement(Node *root, int& K)
{
    if(!root){
        return -1;
    }
    int left = KthSmallestElement(root->left, K);
    if(left != -1){
        return left;
    }
    K--;
    if(K == 0){
        return root->data;
    }
    return KthSmallestElement(root->right, K);
}
