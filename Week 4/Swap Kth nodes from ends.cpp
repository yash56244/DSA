Node *swapkthnode(Node* head, int n, int k)
{
    if(k > n){
        return head;
    }
    if(n == 2*k - 1){
        return head;
    }
    if(n < 2*k - 1){
        k = n - k + 1;
    }
    if(head == NULL){
        return NULL;
    }
    Node *first_prev, *first = head, *second_prev, *second = head;
    for(int i = 0; i < k - 1; i++){
        first_prev = first;
        first = first->next;
    }
    for(int i = 0; i < n - k; i++){
        second_prev = second;
        second = second->next;
    }
    first_prev->next = second;
    second_prev->next = first;
    Node *temp = first->next;
    first->next = second->next;
    second->next = temp;
    if(k == 1){
        head = second;
    }
    return head;
}
