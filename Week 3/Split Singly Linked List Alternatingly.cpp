void alternatingSplitList(struct Node* head) 
{
    bool f = true;
    Node *temp = head, *at = NULL, *bt = NULL;
    while(temp){
        if(f){
            if(temp == head){
                a = new Node(temp->data);
                at = a;
            }else{
                a->next = new Node(temp->data);
                a = a->next;
            }
        }else{
            if(temp == head->next){
                b = new Node(temp->data);
                bt = b;
            }else{
                b->next = new Node(temp->data);
                b = b->next;
            }
        }
        temp = temp->next;
        f = !f;
    }
    a->next = NULL;
    if(b) // for single node
        b->next = NULL;
    a = at;
    b = bt;
}
