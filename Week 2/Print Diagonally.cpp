#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;

void solve()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    for(int x = 0; x < n; x++){
        for(int i = 0, j = x; j >= 0; i++, j--){
            cout<<arr[i][j]<<" ";
        }
    }
    for(int x = n - 1; x > 0; x--){
        for(int i = n - x, j = n - 1; i < n; i++, j--){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}

int main()
{
	int t;
    cin >> t;
    while(t--){
    	solve();
    }
	return 0;
}
