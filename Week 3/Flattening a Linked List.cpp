struct cmp {
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};
Node *flatten(Node *root)
{
    Node *curr = root, *head = NULL;
    priority_queue<Node *, vector<Node *>, cmp> pq;
    while(curr != NULL){
        pq.push(curr);
        curr = curr->next;
    }
    while(!pq.empty()){
        Node *temp = pq.top();
        pq.pop();
        if(temp->bottom){
            pq.push(temp->bottom);
        }
        if(head == NULL){
            head = temp;
        }else{
            curr->bottom = temp;
        }
        curr = temp;
        curr->next = NULL;
    }
    return head;
}

