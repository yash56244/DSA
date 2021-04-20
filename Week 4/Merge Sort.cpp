void merge(int arr[], int l, int m, int r)
{
    int temp[r - l + 1];
    int i = l, j = m + 1, k = 0;
    while(i <= m && j <= r){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= m){
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j <= r){
        temp[k] = arr[j];
        k++;
        j++;
    }
    for(int a = l; a <= r; a++){
        arr[a] = temp[a - l];
    }
}
void mergeSort(int arr[], int l, int r)
{
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
