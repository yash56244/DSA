void removeLoop(Node* head)
{
    if (head == NULL || head->next == NULL) 
        return; 
    Node* slow = head, *fast = head;
    bool loop = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            loop = true;
            break;
        }
    }
    if(loop){
        slow = head;
        if(slow == fast){  // if whole list is loop.
            while(fast->next != slow){
                fast = fast->next;
            }
        }else{
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }   
        }
        fast->next = NULL;
    }
}
