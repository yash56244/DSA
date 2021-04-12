int subarraysWithKDistinct(vector<int>& A, int K) {
    return atMost(A, K) - atMost(A, K - 1);
}
int atMost(vector<int>& arr, int k){
    int res = 0;
    int n = arr.size();
    unordered_map<int, int> ump;
    int left = 0;
    for(int right = 0; right < n; right++){
        if(!ump[arr[right]]){
            k--;
        }
        ump[arr[right]]++;
        while(k < 0){
            ump[arr[left]]--;
            if(!ump[arr[left]]){
                k++;
            }
            left++;
        }
        res += right - left + 1;
    }
    return res;
}
