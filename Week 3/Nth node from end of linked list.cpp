/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n)
{
    Node *ptr1 = head, *ptr2 = head;
    for(int i = 0; i < n; i++){
        if(ptr2 == NULL){
            return -1;
        }
        ptr2 = ptr2->next;
    }
    while(ptr2 != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1->data;
}

