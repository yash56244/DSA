/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int getLength(Node* head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    int cnt = 1;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}   
int intersectPoint(Node* head1, Node* head2)
{
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    if(l1 > l2){
        for(int i = 0; i < l1-l2; i++){
            head1 = head1->next;
        }
    }else if(l2 > l1){
        for(int i = 0; i < l2-l1; i++){
            head2 = head2->next;
        }
    }
    while(head1->next != head2->next && (head1->next!=NULL || head2->next!=NULL)){
        head1 = head1->next;
        head2 = head2->next;
    }
    if(head1->next==NULL || head2->next==NULL){
        return -1;
    }
    return head1->next->data;
}
Node* intersectPoint(Node* head1, Node* head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    if (ptr1 == NULL || ptr2 == NULL) {
  
        return NULL;
    }
    // Traverse through the lists until they
    // reach Intersection node
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        // If at any node ptr1 meets ptr2, then it is
        // intersection node.Return intersection node.
        if (ptr1 == ptr2) {
            return ptr1;
        }
        /* Once both of them go through reassigning,
        they will be equidistant from the collision point.*/
        
        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL) {
            ptr1 = head2;
        }
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL) {
            ptr2 = head1;
        }
    } 
    return ptr1;
}
