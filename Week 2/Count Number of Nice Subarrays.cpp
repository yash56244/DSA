// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.
int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] & 1){
            nums[i] = 1;
        }else{
            nums[i] = 0;
        }
    }
    int cnt = 0;
    unordered_map<int, int> ump;
    int csum = 0, sum = k;
    for(int i = 0; i < n; i++){
        csum += nums[i];
        if(csum == sum){
            cnt++;
        }
        if(ump.find(csum - sum) != ump.end()){
            cnt += ump[csum - sum];
        }
        ump[csum]++;
    }
    return cnt;
}
