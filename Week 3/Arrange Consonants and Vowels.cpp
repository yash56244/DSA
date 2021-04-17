struct Node* arrange(Node *head)
{   
    Node *dummy = new Node(0);
    Node *tdummy = dummy, *temp = head, *prev = head;
    while(temp){
        if(temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u'){
            dummy->next = temp;
            dummy = dummy->next;
            if(temp == head){
                head = head->next;
                temp = head;
            }else{
                prev->next = temp->next;
                temp = temp->next;
            }
        }else{
            prev = temp;
            temp = temp->next;
        }
    }
    dummy->next = head;
    return tdummy->next;
}
