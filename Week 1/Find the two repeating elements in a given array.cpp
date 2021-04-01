#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {4, 2, 4, 5, 2, 3, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Repeating Elements are : ";
	for(int i = 0; i < n; i++){
		if(arr[abs(arr[i])] > 0){
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		}else{
			cout<<abs(arr[i])<<" ";
		}
	}
	return 0;
}
