vector<int> find3Numbers(vector<int> arr, int n) {
    int small[n], large[n];
    small[0] = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < small[i - 1]){
            small[i] = arr[i];
        }else{
            small[i] = small[i - 1];
        }
    }
    large[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > large[i + 1]){
            large[i] = arr[i];
        }else{
            large[i] = large[i + 1];
        }
    }
    for(int i = 1; i < n - 1; i++){
        if(arr[i] > small[i - 1] && arr[i] < large[i + 1]){
            return {small[i - 1], arr[i], large[i + 1]};
        }
    }
    return {};
}
