bool hasArrayTwoCandidates(int arr[], int n, int x) {
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        if(s.find(x - arr[i]) != s.end()){
            return true;
        }else{
            s.insert(arr[i]);
        }
    }
    return false;
}
