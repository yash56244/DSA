// You are given the head of a singly linked-list. The list can be represented as:
// L0 ? L1 ? … ? Ln - 1 ? Ln
// Reorder the list to be on the following form:
// L0 ? Ln ? L1 ? Ln - 1 ? L2 ? Ln - 2 ? …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.
void reorderList(ListNode* head) {
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *sec = reverseList(slow->next);
    slow->next = NULL;
    ListNode *t1 = head, *t2 = sec;
    while(t1 && t2){
        ListNode *aux1 = t1->next, *aux2 = t2->next;
        t1->next = t2;
        t2->next = aux1;
        t1 = aux1;
        t2 = aux2;
    }
}
