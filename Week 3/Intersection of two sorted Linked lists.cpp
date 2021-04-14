Node* findIntersection(Node* head1, Node* head2)
{
    Node *temp = new Node(-1);
    Node *tt = temp;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            head1 = head1->next;
        }else if(head1->data == head2->data){
            Node *aux = new Node(head1->data);
            temp->next = aux;
            temp = temp->next;
            head1 = head1->next;
            head2 = head2->next;
        }else{
            head2 = head2->next;
        }
    }
    return tt->next;
}
