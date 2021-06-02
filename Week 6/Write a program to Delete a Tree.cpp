void deleteTree(node* node) 
{ 
    if (node == NULL) return; 
  
    deleteTree(node->left); 
    deleteTree(node->right); 
    
    cout << "\n Deleting node: " << node->data; 
    delete node;
}
