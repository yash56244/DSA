void linkdelete(struct Node  *head, int m, int n)
{
    Node *temp = head;
    while(temp){
        int i = 1;
        while(temp && i < m){
            temp = temp->next;
            i++;
        }
        if(!temp){
            return;
        }
        i = 0;
        Node *t2 = temp->next;
        while(t2 && i < n){
            t2 = t2->next;
            i++;
        }
        temp->next = t2;
        temp = t2;
    }
}
