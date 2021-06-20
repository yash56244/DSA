void MatrixUtil(Node *root,int index){
         
    if(root==NULL)return;
     
        int preData=root->data;
        if(index==-1)index=root->data;
        else  M[index][preData]=1;   
     
    MatrixUtil(root->left,preData);
    MatrixUtil(root->right,preData);
}
