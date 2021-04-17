Node* segregate(Node *head) {
    
    if (!head || !(head->next)) 
        return head; 
    Node* zeroD = new Node(0); 
    Node* oneD = new Node(0); 
    Node* twoD = new Node(0);
    Node* zero = zeroD, *one = oneD, *two = twoD; 
  
    Node* curr = head; 
    while (curr) { 
        if (curr->data == 0) { 
            zero->next = curr; 
            zero = zero->next; 
            curr = curr->next; 
        } else if (curr->data == 1) { 
            one->next = curr; 
            one = one->next; 
            curr = curr->next; 
        } else { 
            two->next = curr; 
            two = two->next; 
            curr = curr->next; 
        } 
    } 
  
    zero->next = (oneD->next)  
? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 
  
    head = zeroD->next; 
  
    delete zeroD; 
    delete oneD; 
    delete twoD; 
  
    return head; 
    
}
Node* segregate(Node *head) {
    int cnt[3] = {0};
    Node *temp = head, *temp2 = head;
    while(temp){
        cnt[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    int i = 0;
    while(temp){
        if(cnt[i] == 0){
            i++;
        }else{
            temp->data = i;
            cnt[i]--;
            temp = temp->next;
        }
    }
    return temp2;
}
