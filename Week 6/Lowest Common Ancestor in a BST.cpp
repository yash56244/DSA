Node* lca(Node *root, int n1, int n2){
    if(!root){
        return root;
    }
    if(root->data >= n1 && root->data <= n2){
        return root;
    }else if(root->data < n1){
        return lca(root->right, n1, n2);
    }else{
        return lca(root->left, n1, n2);
    }
}
Node* LCA(Node *root, int n1, int n2)
{
    if(n1 > n2){
        swap(n1, n2);
    }
    return lca(root, n1, n2);
}

