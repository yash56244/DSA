class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        set<vector<int>> s;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                int l = j + 1;
                int r = n - 1;
                while(l < r){
                    long long sum = arr[i] + arr[j] + arr[l] + arr[r];
                    if(sum == target){
                        s.insert({arr[i], arr[j], arr[l], arr[r]});
                        while(l < n - 1 && arr[l] == arr[l + 1]){
                            l++;
                        }
                        while(r > 0 && arr[r] == arr[r - 1]){
                            r--;
                        }
                        l++;
                        r--;
                    }else if(sum < target){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
