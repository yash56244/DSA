//Function to serialize a tree and return a list containing nodes of tree.
vector<int> serialize(Node *root) 
{
    vector<int> v;
    stack<Node*> s;
    Node* curr = root;
    while(!s.empty() || curr != NULL){
        if(curr){
            s.push(curr);
            curr = curr->left;
        }else{
            curr = s.top();
            s.pop();
            v.push_back(curr->data);
            curr = curr->right;
        }
    }
    return v;
}

//Function to deserialize a list and construct the tree.
Node* rec(vector<int> &A, int l, int h){
    if(l <= h){
        int m = (l + h) / 2;
        Node* curr = new Node(A[m]);
        curr->left = rec(A, l , m - 1);
        curr->right = rec(A, m + 1, h);
        return curr;
    }else{
        return NULL;
    }
}
Node * deSerialize(vector<int> &A)
{
    return rec(A, 0, A.size() - 1);
}
