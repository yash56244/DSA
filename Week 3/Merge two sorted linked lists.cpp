Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node *dummy = new Node(-1);
    Node *nHead = dummy;
    while(head1 != NULL || head2 != NULL){
        if(!head1){
            dummy->next = head2;
            break;
        }
        if(!head2){
            dummy->next = head1;
            break;
        }
		if(head1->data >= head2->data){
            dummy->next = head2;
            dummy = dummy->next;
            head2 = head2->next;
        }else{
            dummy->next = head1;
            dummy = dummy->next;
            head1 = head1->next;
        }
    }
    return nHead->next;
}
