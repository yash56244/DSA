void populateNext(struct node* p)
{
    static node* prev = NULL;
    if(p == NULL){
        return;
    }
    populateNext(p->left);
    if(prev != NULL){
        prev->next = p;
    }
    prev = p;
    populateNext(p->right);
}
