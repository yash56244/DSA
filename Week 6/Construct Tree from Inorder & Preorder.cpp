class Solution{
    public:
    unordered_map<int, int> m;
    int i = 0;
    Node* rec(int in[],int pre[], int l, int h){
        if(l > h)
            return NULL;
        Node* curr = new Node(pre[i]);
        int idx = m[pre[i]];
        i++;
        curr->left = rec(in, pre, l, idx - 1);
        curr->right = rec(in, pre, idx + 1, h);
        return curr;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        for(int i = 0; i < n; i++){
            m[in[i]] = i;
        }
        return rec(in, pre, 0, n - 1);
    }
};
