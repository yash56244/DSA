#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int j = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] < 0){
			swap(arr[i], arr[j]);
			j++;
		}
	}
	int neg = 0, pos = j;
	while(pos < n && neg < pos && arr[neg] < 0){
		swap(arr[neg], arr[pos]);
		neg += 2;
		pos++;
	}
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<' ';
	}
	return 0;
}
