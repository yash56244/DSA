void deleteLinkedList(Node **head){
	Node *temp = *head;
	while(temp != NULL){
		Node *nxt = temp->next;
		free(temp);
		temp = nxt;
	}
	*head = NULL;
}
