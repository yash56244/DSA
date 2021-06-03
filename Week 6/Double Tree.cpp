void doubleTree(node* Node) 
{ 
    if (Node == NULL) return; 
    doubleTree(Node->left); 
    doubleTree(Node->right); 
    node* oldLeft = Node->left; 
    Node->left = new node(Node->data); 
    Node->left->left = oldLeft; 
} 
