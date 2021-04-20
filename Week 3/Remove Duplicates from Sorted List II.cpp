// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
// Return the linked list sorted as well.
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *prev = NULL, *temp = head;
    bool isHeadD = false;
    while(temp && temp->next){
        if(temp->val == temp->next->val){
            if(temp == head){
                isHeadD = true;
                head = head->next;
            }else{
                while(temp->next && temp->val == temp->next->val){
                    temp = temp->next;
                }
            }
            temp = temp->next;
        }else{
            if(prev == NULL){
                prev = head;    
            }else{
                prev->next = temp;
                prev = prev->next;
            }
            temp = temp->next;
        }
    }
    if(prev)
        prev->next = temp;
    if(isHeadD){
        head = head->next;
    }
    return head;
}
