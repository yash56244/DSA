int findParent(int i, vector<int> &parent) {
    if (i == parent[i]) {
        return i;
    }

    return parent[i] = findParent(parent[i], parent);
}
string solve(string a, string b, string target) {
    vector<int> parent(26);
    for (int i = 0; i < 26; i++) {
        parent[i] = i;
    }
    int n = a.length();
    for(int i = 0; i < n; i++){
        int i1 = a[i] - 'a';
        int j1 = b[i] - 'a';
        int left = findParent(i1, parent);
        int right = findParent(j1, parent);
        if (left != right) {
        	parent[right] = left;
        }
    }
    string ans = "";
    int m = target.length();
    for(int i = 0; i < m; i++){
        int i1 = target[i] - 'a';
        for(int j = 0; j < 26; j++){
            int left = findParent(i1, parent);
            int right = findParent(j, parent);
            if (left == right) {
                ans += j + 'a';
                break;
            }
        }
    }
    return ans;
}
