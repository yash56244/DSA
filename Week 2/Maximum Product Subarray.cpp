long long maxProduct(int *arr, int n) {
    long long maxv = 1, minv = 1, ans = INT64_MIN;
    bool firstNeg = true;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            maxv = maxv * arr[i];
            minv = min((long long)1, minv * arr[i]);
        }else if(arr[i] < 0){
            long long t = maxv;
            maxv = max((long long)1, minv * arr[i]);
            minv = min((long long)1, t * arr[i]);
        }else{
            maxv = 0;
            minv = 1;
        }
        ans = max(ans, maxv);
        if(maxv == 0){
            maxv = 1;
        }
    }
    return ans;
}
