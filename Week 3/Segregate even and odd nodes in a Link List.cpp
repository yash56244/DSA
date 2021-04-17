Node* divide(int N, Node *head){
    // code here
    Node *dummy = new Node(0);
    Node *tdummy = dummy, *temp = head, *prev = head;
    while(temp){
        if(temp->data % 2 == 0){
            dummy->next = temp;
            dummy = dummy->next;
            if(temp == head){
                head = head->next;
                temp = head;
            }else{
                prev->next = temp->next;
                temp = temp->next;
            }
        }else{
            prev = temp;
            temp = temp->next;
        }
    }
    dummy->next = head;
    return tdummy->next;
}
