int maxLen(int arr[], int n)
{
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            arr[i] = -1;
        }
    }
    unordered_map<int, int> s;
    int sum = 0, omax = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0){
            omax = i + 1;
        }
        if(s.find(sum) != s.end()){
            omax = max(omax, i - s[sum]);
        }else{
            s[sum] = i;
        }
    }
    return omax;
}
