#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {12, 34, 45, 9, 8, 90, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int j = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] % 2 == 0){
			swap(arr[i], arr[j]);
			j++;
		}
	}
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
