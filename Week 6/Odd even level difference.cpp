int oddsum = 0, evensum = 0;
void rec(Node *root, bool odd){
    if(!root){
        return;
    }
    if(odd){
        oddsum += root->data;
        if(root->left){
            rec(root->left, false);
        }
        if(root->right){
            rec(root->right, false);
        }
    }else{
        evensum += root->data;
        if(root->left){
            rec(root->left, true);
        }
        if(root->right){
            rec(root->right, true);
        }
    }
}
int getLevelDiff(Node *root)
{
    rec(root, true);
    return oddsum - evensum;
}
