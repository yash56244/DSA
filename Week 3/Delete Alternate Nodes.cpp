void deleteAlt(struct Node *head){
    if(head == NULL){
        return;
    }
    Node *temp = head->next;
    Node *prev = head;
    while(temp != NULL && prev != NULL){
        Node *aux = temp->next;
        free(temp);
        prev->next = aux;
        if(aux != NULL)
            temp = aux->next;
        prev = aux;
    }
}
