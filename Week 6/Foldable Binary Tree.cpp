bool IsFoldableUtil(Node* n1, Node* n2)
{
    if (n1 == NULL && n2 == NULL) {
        return true;
    }
 
    if (n1 == NULL || n2 == NULL) {
        return false;
    }
 
    return IsFoldableUtil(n1->left, n2->right)
           && IsFoldableUtil(n1->right, n2->left);
}
bool IsFoldable(Node* root)
{
    if (root == NULL) {
        return true;
    }
 
    return IsFoldableUtil(root->left, root->right);
}
