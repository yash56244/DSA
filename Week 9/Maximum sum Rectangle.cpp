int kadane(int arr[],int n){
    int currmax = arr[0],maxsum = arr[0];
    for(int i = 1; i < n; i++){
        currmax = max(arr[i],currmax + arr[i]);
        maxsum = max(maxsum,currmax);
    }
    return maxsum;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    int arr[R];
    int ans = INT_MIN;
    for(int c = 0; c < C; c++){
        memset(arr,0,sizeof(arr));
        for(int r = c; r < C; r++){
            for(int i = 0; i < R; i++){
                arr[i] += M[i][r];
            }
            ans = max(ans,kadane(arr,R));
        }
    }
    
    return ans;
}
