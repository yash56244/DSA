struct Node* rev(struct Node *head)
{
    Node* temp;
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return head = prev;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node *a = rev(first);
    Node *b = rev(second);
    Node *at = a;
    Node *bt = b;
    Node *ans = new Node(-1), *anst = ans;
    int sum, carry = 0;
    while(at && bt){
        sum = at->data + bt->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans->next = new Node(sum);
        ans = ans->next;
        at = at->next;
        bt = bt->next;
    }
    if(at){
        while(carry != 0 && at){
            sum = carry + at->data;
            carry = sum / 10;
            sum = sum % 10;
            ans->next = new Node(sum);
            ans = ans->next;
            at = at->next;
        }
        ans->next = at;
    }else if(bt){
        while(carry != 0 && bt){
            sum = carry + bt->data;
            carry = sum / 10;
            sum = sum % 10;
            ans->next = new Node(sum);
            ans = ans->next;
            bt = bt->next;
        }
        ans->next = bt;
    }
    if(carry != 0){
        ans->next = new Node(carry);
    }
    anst = anst->next;
    anst = rev(anst);
    return anst;
}
