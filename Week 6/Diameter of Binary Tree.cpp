int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
int diameter(Node* root) {
    if(root == NULL){
        return 0;
    }
    return max(diameter(root->left), max(diameter(root->right), height(root->right) + height(root->left) + 1));
}
