vector<int> v;
void rec(vector<int> &nums, int l, int r){
    if(l <= r){
        int m = (l + r)/2;
        v.push_back(nums[m]);
        rec(nums, l, m - 1);
        rec(nums, m + 1, r);
    }
}
vector<int> sortedArrayToBST(vector<int>& nums) {
    rec(nums, 0, nums.size() - 1);
    return v;
}
