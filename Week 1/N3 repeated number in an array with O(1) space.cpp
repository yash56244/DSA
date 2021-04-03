#include<bits/stdc++.h>

using namespace std;

int repeatedNumber(int arr[], int n) {
    bool flag = false;
    int ans;
    for(int i = 0; i < 25; i++){
        int idx = rand()%n;
        int ele = arr[idx];
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ele == arr[i]){
                cnt++;
            }
        }
        if(cnt > n / 3){
            flag = true;
            ans = ele;
            break;
        }
    }
    if(flag){
        return ans;
    }else{
        return -1;
    }
}

int main(){
	int arr[] = {10, 10, 20, 30, 10, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<repeatedNumber(arr, n);
	return 0;
}
