int search(int arr[], int l, int h, int key){
    while(l <= h){
        int m = l + (h - l) / 2;
        if(arr[m] == key){
            return m;
        }else if(arr[m] > arr[l]){ //Left side Sorted
            if(key >= arr[l] && key <= arr[m]){
                h = m - 1;
            }else{
                l = m + 1;
            }
        }else{ //Right side Sorted
            if(key >= arr[m] && key <= arr[h]){
                l = m + 1;
            }else{
                h = m - 1;
            }
        }
    }
    return -1;
}
