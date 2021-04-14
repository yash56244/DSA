Node* rotate(Node* head_ref, int k)
{
    if(k == 0){
        return head_ref;
    }
    Node* current = head_ref; 
    while (current->next != NULL) 
        current = current->next; 
    current->next = head_ref; 
    current = head_ref; 
    for (int i = 0; i < k - 1; i++) 
        current = current->next; 
    head_ref = current->next; 
    current->next = NULL; 
    return head_ref;
}
