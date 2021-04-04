// Method 1
bool find3Numbers(int A[], int arr_size, int sum)
{
    for (int i = 0; i < arr_size - 2; i++) 
    {
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++) 
        {
            if (s.find(curr_sum - A[j]) != s.end()) 
            {
                return true;
            }
            s.insert(A[j]);
        }
    }
    return false;
}
// Method 2
bool find3Numbers(int arr[], int n, int x)
{
    sort(arr, arr + n);
    for(int i = 0; i < n - 2; i++){
        int l = i + 1;
        int r = n - 1;
        while(l < r){
            if(arr[i] + arr[l] + arr[r] == x){
                return true;
            }else if(arr[i] + arr[l] + arr[r] < x){
                l++;
            }else{
                r--;
            }
        }
    }
    return false;
}
