#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {1000, 11, 445, 1, 330, 3000};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i, mn, mx;
	if(n % 2 == 0){
		mn = min(arr[0], arr[1]);
		mx = max(arr[0], arr[1]);
		i = 2;
	}else{
		mn = mx = arr[0];
		i = 1;
	}
	while(i < n - 1){
		mn = min(mn, min(arr[i], arr[i+1]));
		mx = max(mx, max(arr[i], arr[i+1]));
		i += 2;
	}
	cout<<"Minimum element is "<<mn<<" and maximum is "<<mx;
	return 0;
}
