int maxAscendingSum(vector<int>& nums) {
    int maxe = nums[0];
    int omax = nums[0];
    int n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i] > nums[i - 1]){
            maxe += nums[i];
            omax = max(omax, maxe);
        }else{
            maxe = nums[i];
        }
    }
    return omax;
}
