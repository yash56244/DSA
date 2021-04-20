void quickSort(int arr[], int low, int high)
{
    if(low < high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
int partition (int arr[], int low, int high)
{
    int rp = rand() % (high - low + 1);
    swap(arr[low + rp], arr[high]);
    int pivot = arr[high];
    int i = low;
    for(int j = low; j <= high; j++){
        if(arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
