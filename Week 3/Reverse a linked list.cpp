struct Node* reverseList(struct Node *head)
{
    Node* temp;
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return head = prev;
}
