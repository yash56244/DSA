int subArraySum(int arr[], int n, int sum)
{
    int cnt = 0;
    unordered_map<int, int> ump;
    int csum = 0;
    for(int i = 0; i < n; i++){
        csum += arr[i];
        if(csum == sum){
            cnt++;
        }
        if(ump.find(csum - sum) != ump.end()){
            cnt += ump[csum - sum];
        }
        ump[csum]++;
    }
    return cnt;
}
