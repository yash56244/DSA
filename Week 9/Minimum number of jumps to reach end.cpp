int minJumps(int arr[], int n)
{
    int* jumps = new int[n];
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
    jumps[0] = 0;
    for (int i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}
