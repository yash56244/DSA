struct node *reverse (struct node *head, int k, bool rev)
{ 
    if(head == NULL){
        return NULL;
    }
    int cnt = 0;
    node *prev = NULL, *curr = head;
    while(curr != NULL && cnt < k){
    	if(rev){
	        node *aux = curr->next;
	        curr->next = prev;
	        prev = curr;
	        curr = aux;	
		}else{
			prev = curr;
			curr = curr->next;	
		}
        cnt++;
    }
    if(rev){
    	head->next = reverse(curr, k, !rev);
    	return prev;
	}else{
		prev->next = reverse(curr, k, !rev);
		return head;
	}
}
