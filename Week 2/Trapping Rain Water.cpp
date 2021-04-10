int trap(vector<int>& height) {
    int n = height.size();
    int water = 0;
    int left_max = 0, right_max = 0;
    int l = 0, h  = n - 1;
    while(l < h){
        if(height[l] < height[h]){
            if(height[l] > left_max){
                left_max = height[l];
            }else{
                water += left_max - height[l];
            }
            l++;   
        }else{
            if(height[h] > right_max){
                right_max = height[h];
            }else{
                water += right_max - height[h];
            }
            h--;
        }
    }
    return water;
}
