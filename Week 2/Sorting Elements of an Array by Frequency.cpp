#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int maxe = INT_MIN;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            maxe = max(maxe, arr[i]);
        }
        int freq[maxe + 1];
        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
        }
        vector<pair<int, int>> vii;
        for(int i = 1; i <= maxe; i++){
            if(freq[i] != 0)
                vii.push_back({freq[i], i});
        }
        sort(vii.begin(), vii.end(), cmp);
        for(int i = 0; i < vii.size(); i++){
            while(vii[i].first > 0){
                cout<<vii[i].second<<" ";
                vii[i].first--;
            }
        }
        cout<<endl;
    }
	return 0;
}
