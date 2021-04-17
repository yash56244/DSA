Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node *dummy = new Node(-1);
    Node *nHead = dummy;
    while(head1 != NULL || head2 != NULL){
        if(!head1){
            dummy->next = head2;
            break;
        }
        if(!head2){
            dummy->next = head1;
            break;
        }
		if(head1->data >= head2->data){
            dummy->next = head2;
            dummy = dummy->next;
            head2 = head2->next;
        }else{
            dummy->next = head1;
            dummy = dummy->next;
            head1 = head1->next;
        }
    }
    nHead = nHead->next;
    return nHead;
}
void split(Node *head, Node **a, Node **b){
	Node *slow = head, *fast = head->next;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}
void mergesort(Node **head){
	Node *temp = *head;
	Node *firstHalf, *secondHalf;
	if(temp == NULL || temp->next == NULL){
		return;
	}
	split(temp, &firstHalf, &secondHalf);
	mergesort(&firstHalf);
	mergesort(&secondHalf);
	*head = sortedMerge(firstHalf, secondHalf);
}
void reverse(Node **head)
{
    Node* current = *head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
        next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void tripletWithSum(Node *a, Node *b, Node *c, int sum){
	mergesort(&b); // sort b in asceding order.
	mergesort(&c); 
	reverse(&c); // sort c in descending order.
	Node *h1 = a;
	while(h1){
		Node *h2 = b;
		Node *h3 = c;
		while(h2 && h3){
			int sm = h1->data + h2->data + h3->data;
			if(sm == sum){
				cout<<"Triplet found at "<<h1->data<<" "<<h2->data<<" "<<h3->data;
				return;
			}else if(sm < sum){
				h2 = h2->next;
			}else{
				h3 = h3->next;
			}
		}
	}
	cout<<"Not Found.";
}
