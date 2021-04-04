#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {0, 1, 2, 0, 1, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int l = 0, m = 0, h = n - 1;
	while(m <= h){
		if(arr[m] == 0){
			swap(arr[m], arr[l]);
			m++;
			l++;
		}else if(arr[m] == 1){
			m++;
		}else{
			swap(arr[m], arr[h]);
			h--;
		}
	}
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<' ';
	}
	return 0;
}
