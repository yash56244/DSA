Node* findIntersection(Node* head1, Node* head2)
{
    unordered_set<int> s;
    while(head2 != NULL){
        s.insert(head2->data);
        head2 = head2->next;
    }
    Node *head = new Node(-1);
    Node *tt = head;
    while(head1 != NULL){
        if(s.find(head1->data) != s.end()){
            Node *aux = new Node(head1->data);
            head->next = aux;
            head = head->next;
        }
        head1 = head1->next;
    }
    return tt->next;
}
