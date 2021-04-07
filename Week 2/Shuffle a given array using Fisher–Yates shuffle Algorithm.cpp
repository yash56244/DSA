#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	srand(time(0));
	for(int i = n - 1; i >= 0; i--){
		int j = rand() % (i + 1);
		swap(arr[i], arr[j]);
	}
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<' ';
	}
	return 0;
}
