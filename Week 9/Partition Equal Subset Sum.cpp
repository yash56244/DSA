int equalPartition(int n, int arr[])
{
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    if(sum & 1){
        return 0;
    }
    sum /= 2;
    bool subset[2][sum + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0)
                subset[i % 2][j] = true;
            else if (i == 0)
                subset[i % 2][j] = false;
            else if (arr[i - 1] <= j)
                subset[i % 2][j] = subset[(i + 1) % 2][j - arr[i - 1]] || subset[(i + 1) % 2][j];
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j];
        }
    }
    return subset[n % 2][sum];
}
