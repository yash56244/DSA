int select(int arr[], int i, int n)
{
    int mini = i;
    for(int j = i; j < n; j++){
        if(arr[mini] > arr[j]){
            mini = j;
        }
    }
    return mini;
}
 
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++){
        int j = select(arr, i, n);
        swap(&arr[j], &arr[i]);
    }
}
