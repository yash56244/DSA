vector<int> rec(Node * root){
    if(!root){
        return {1,0,INT_MAX,0};
    }
    vector<int> a = rec(root->left);
    vector<int> b = rec(root->right);
    if(a[0]==1 && b[0]==1 && root->data>a[3] && root->data<b[2]){ 
        return {1,a[1]+b[1]+1,min(root->data,min(a[2],b[2])),max(root->data,max(a[3],b[3]))};
    }
    else{
        return{0,max(a[1],b[1]),0,0};
    }
}
int largestBst(Node *root)
{
    vector<int> ans = rec(root);
    return ans[1];
}
