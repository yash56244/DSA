int minValue(Node* root)
{
    if(root->left){
        return minValue(root->left);
    }else{
        return root->data;
    }
}

