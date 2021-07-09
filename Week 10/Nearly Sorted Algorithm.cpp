#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int ll;

void solve()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }
    for(int i = k; i < n; i++){
        pq.push(arr[i]);
        cout<<pq.top()<<" ";
        pq.pop();
    }
    while(!pq.empty()){
        cout<<pq.top()<<' ';
        pq.pop();
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
