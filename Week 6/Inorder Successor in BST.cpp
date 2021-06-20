Node * inOrderSuccessor(Node *root, Node *n)
{
    if (n->right != NULL){
        Node* current = n->right;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    Node* succ = NULL;
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
            break;
    }
 
    return succ;
}
