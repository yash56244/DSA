vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
    long long int left[n], right[n];
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];
    for(int i = 1; i < n; i++){
        left[i] = left[i - 1] * arr[i];
    }
    for(int i = n - 2; i >= 0; i--){
        right[i] = arr[i] * right[i + 1];
    }
    vector<long long int> res(n);
    res[0] = (n == 1) ? 1 : right[1];
    res[n - 1] = (n == 1) ? 1 : left[n - 2];
    for(int i = 1; i < n - 1; i++){
        res[i] = left[i - 1] * right[i + 1];
    }
    return res;
}
