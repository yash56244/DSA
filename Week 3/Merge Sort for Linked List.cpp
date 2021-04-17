/* MergeSort(headRef)
1) If the head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b); // a and b are two halves.
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b); */

Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node *dummy = new Node(-1);
    Node *nHead = dummy;
    while(head1 != NULL || head2 != NULL){
        if(!head1){
            dummy->next = head2;
            break;
        }
        if(!head2){
            dummy->next = head1;
            break;
        }
		if(head1->data >= head2->data){
            dummy->next = head2;
            dummy = dummy->next;
            head2 = head2->next;
        }else{
            dummy->next = head1;
            dummy = dummy->next;
            head1 = head1->next;
        }
    }
    nHead = nHead->next;
    return nHead;
}
void split(Node *head, Node **a, Node **b){
	Node *slow = head, *fast = head->next;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}
void mergesort(Node **head){
	Node *temp = *head;
	Node *firstHalf, *secondHalf;
	if(temp == NULL || temp->next == NULL){
		return;
	}
	split(temp, &firstHalf, &secondHalf);
	mergesort(&firstHalf);
	mergesort(&secondHalf);
	*head = sortedMerge(firstHalf, secondHalf);
}
Node* mergeSort(Node* head) {
    mergesort(&head);
    return head;
}
