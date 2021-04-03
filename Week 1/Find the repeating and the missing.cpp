#include<bits/stdc++.h>

using namespace std;

pair<int, int> repeatedNumber(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans ^= arr[i];
    }
    for(int i = 1; i <= n; i++){
        ans ^= i;
    }
    int rightmost = ans & ~(ans - 1);
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] & rightmost){
            a ^= arr[i];
        }else{
            b ^= arr[i];
        }
    }
    for(int i = 1; i <= n; i++){
        if(i & rightmost){
            a ^= i;
        }else{
            b ^= i;
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == a){
            return {a, b};
        }
    }
    return {b, a};
}

int main(){
	int arr[] = {4,3,6,5,2,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	pair<int, int>p = repeatedNumber(arr, n);
	cout << "The repeated number is "<<p.first<<" and missing is "<<p.second;
	return 0;
}
