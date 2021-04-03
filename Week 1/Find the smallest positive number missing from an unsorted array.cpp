#include<bits/stdc++.h>

using namespace std;

void findMissing(int arr[], int n){
		int j = 0;
    	for(int i = 0; i < n; i++){
    		if(arr[i] <= 0){
    			swap(arr[j], arr[i]);
    			j++;
    		}
    	}
    	arr = arr + j;
    	n = n - j;
    	int pos = n + 1;
    	for(int i = 0; i < n; i++){
    		if(abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0){
    			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    		}
    	}
    	for(int i = 0; i < n; i++){
    		if(arr[i] > 0){
    			pos = i + 1;
    			break;
    		}
    	}
		cout<<"The smallest positive missing number is : "<<pos;
}

int main(){
	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr)/sizeof(arr[0]);
	findMissing(arr, n);
	return 0;
}
