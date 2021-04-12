void printRev(Node* head){
	if(head == NULL){
		return;
	}
	printRev(head->next);
	cout<<head->data<<" ";
}
