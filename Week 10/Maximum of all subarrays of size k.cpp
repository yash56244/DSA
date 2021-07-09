vector <int> max_of_subarrays(int *arr, int n, int k)
{
    multiset<int,greater<int>> st;
	for(int i = 0; i < k; i++) {
		st.insert(arr[i]);
	}
	vector<int> ans; 
	ans.push_back(*st.begin());
	for(int i = 1; i <= n-k; i++) {
		st.erase(st.find(arr[i-1]));
		st.insert(arr[k+i-1]);
		ans.push_back(*st.begin());
	}
	return ans;
}
// Another method in O(n)
vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for(int i = 0; i < k; i++){
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i = k; i < n; i++){
        ans.push_back(arr[dq.front()]);
        while(!dq.empty() && dq.front() <= (i - k)){
            dq.pop_front();
        }
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    return ans;
}
