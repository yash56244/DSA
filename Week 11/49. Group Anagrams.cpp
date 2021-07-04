int n = arr.size();
vector<pair<string, int>> v;
for(int i = 0; i < n; i++){
    v.push_back({sort(arr[i].begin(), arr[i].end(), i});
}
sort(v.begin(), v.end());
vector<string> ans;
for(int i = 0; i < n; i++){
    ans.push_back(arr[v[i].second]);
}
return ans;
