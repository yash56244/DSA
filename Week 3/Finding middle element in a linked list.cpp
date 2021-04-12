int getMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
void printMiddle(struct node* head)
{
    int count = 0;
    struct node* mid = head;

    while (head != NULL)
    {
        // Update mid, when 'count'
        // is odd number 
        if (count & 1)
            mid = mid->next;

        ++count;
        head = head->next;
    }

    if (mid != NULL)
        printf("The middle element is [%d]\n\n", 
                mid->data);
}
