bool isMajority(int arr[], int n, int x){
	int l = 0, h = n - 1, i = -1;
	while(l < h){
		int m = l + (h - l) / 2;
		if((m == 0 || arr[m - 1] < x) && arr[m] == x){
			i = m;
			break;
		}else if(arr[m] < x){
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	if(i != -1 && i + n / 2 < n){
		if(arr[i + n / 2] == x){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
