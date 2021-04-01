#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {1, 2, 4, 6, 3, 7, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	n++;
	int missing = 0;
	for(int i = 0; i < n - 1; i++){
		missing ^= arr[i];
	}
	for(int i = 1; i <= n; i++){
		missing ^= i;
	}
	cout<<missing;
	return 0;
}
