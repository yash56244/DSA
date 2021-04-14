//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || k == 1) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next=head;
    ListNode *curr = dummy, *nex = dummy, *prev = dummy;
    int count = 0;
    while(curr->next!=NULL){
        curr = curr->next;
        count++;
    }
    while(count >= k){
        curr = prev->next;
        nex = curr->next;
        for(int i = 1; i < k; i++){
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev = curr;
        count-=k;
    }
    return dummy->next;
}
// Recursive
//Given a linked list, write a function to reverse every k nodes (where k is an input to the function). 
struct node *reverse (struct node *head, int k)
{ 
    if(head == NULL){
        return NULL;
    }
    int cnt = 0;
    node *prev = NULL, *curr = head;
    while(curr != NULL && cnt < k){
        node *aux = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aux;
        cnt++;
    }
    head->next = reverse(curr, k);
    return prev;
}
