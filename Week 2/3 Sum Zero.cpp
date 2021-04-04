//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
//Find all unique triplets in the array which gives the sum of zero.
vector<vector<int> > Solution::threeSum(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int> > ans;
    int n = arr.size();
    int x = 0;
    for(int i = 0; i < n - 2; i++){
        if(arr[i] == arr[i - 1]){
            continue;
        }
        int l = i + 1;
        int r = n - 1;
        while(l < r){
            long sum = (long)arr[i] + arr[l] + arr[r];
            if(sum == x ){
                vector<int> v;
                v.push_back(arr[i]);
                v.push_back(arr[l]);
                v.push_back(arr[r]);
                ans.push_back(v);
                while(arr[l] == arr[l + 1] && l < r){
                    l++;
                }
                while(arr[r] == arr[r - 1] && r > l){
                    r--;
                }
                l++;
                r--;
            }else if(sum < x){
                l++;
            }else{
                r--;
            }
        }
    }
    return ans;
}
