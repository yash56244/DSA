struct Node* insert(struct Node *head, int data)
{
    Node *temp = new Node(data);
    temp->npx = head;
    if(head){
        head->npx = XOR(temp, head->npx);
    }
    return temp;
}

vector<int> printList (struct Node *head)
{
    Node *curr = head, *prev = NULL, *next;
    vector<int> res;
    while(curr){
        res.push_back(curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    return res;
}
