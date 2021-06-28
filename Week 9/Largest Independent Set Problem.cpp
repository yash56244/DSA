int LISS(node *root)
{
    if (root == NULL)
        return 0;
 
    if (root->liss)
        return root->liss;
 
    if (root->left == NULL && root->right == NULL)
        return (root->liss = 1);
 
    int liss_excl = LISS(root->left) + LISS(root->right);
 
    int liss_incl = 1;
    if (root->left)
        liss_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
        liss_incl += LISS(root->right->left) + LISS(root->right->right);
 
    root->liss = max(liss_incl, liss_excl);
 
    return root->liss;
}
