#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {4, 5, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	int l = 0, r = n - 1;
	while(l < r){
		swap(arr[l], arr[r]);
		r--, l++;
	}
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
