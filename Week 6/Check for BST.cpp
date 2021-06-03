bool isBST(Node* root, int min = INT_MIN, int max = INT_MAX) 
    {
        if(!root){
            return true;
        }
        if(root->data < min || root->data > max){
            return false;
        }else{
            isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
        }
    }
