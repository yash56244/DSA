#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;
const int maxn = 1e7 + 1;
int arr[maxn];
void solve()
{
    int n, d;
    cin>>n>>d;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    d %= n;
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
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
