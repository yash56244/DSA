Node* ancestorTree(int mat[][N])
{
    // Binary array to determine whether
    // parent is set for node i or not
    int parent[N] = {0};
   
    // Root will store the root of the constructed tree
    Node* root = NULL;
   
    // Create a multimap, sum is used as key and row
    // numbers are used as values
    multimap<int, int> mm;
   
    for (int i = 0; i < N; i++)
    {
        int sum = 0; // Initialize sum of this row
        for (int j = 0; j < N; j++)
            sum += mat[i][j];
   
        // insert(sum, i) pairs into the multimap
        mm.insert(pair<int, int>(sum, i));
    }
   
    // node[i] will store node for i in constructed tree
    Node* node[N];
   
    // Traverse all entries of multimap.  Note that values
    // are accessed in increasing order of sum
    for (auto it = mm.begin(); it != mm.end(); ++it)
    {
      // create a new node for every value
      node[it->second] = new Node(it->second);
   
      // To store last processed node. This node will be
      // root after loop terminates
      root = node[it->second];
   
      // if non-leaf node
      if (it->first != 0)
      {
        // traverse row 'it->second' in the matrix
        for (int i = 0; i < N; i++)
        {
           // if parent is not set and ancestor exits
           if (!parent[i] && mat[it->second][i])
           {
             // check for unoccupied left/right node
             // and set parent of node i
             if (!node[it->second]->left)
               node[it->second]->left = node[i];
             else
               node[it->second]->right = node[i];
   
             parent[i] = 1;
           }
        }
      }
    }
    return root;
}
