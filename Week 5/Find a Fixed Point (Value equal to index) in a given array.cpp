int fixedPoint(int arr[], int n){
	int l = 0, h = n - 1;
	while(l <= h){
		int m = l + (h - l) / 2;
		if(m == arr[m]){
			return m;
		}else if(m > arr[m]){
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	return -1;
}
