int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k <= 1){
        return 0;
    }
    int n = nums.size();
    int i = 0, prod = 1, res = 0;
    for(int j = 0; j < n; j++){
        prod *= nums[j];
        while(prod >= k){
            prod /= nums[i];
            i++;
        }
        res += j - i + 1;
    }
    return res;
}
