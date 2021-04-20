void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++){
        bool sorted = true;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j + 1] < arr[j]){
                sorted = false;
                swap(&arr[j + 1], &arr[j]);
            }
        }
        if(sorted){
            return;
        }
    }
}
