int mySqrt(int x) {
    if(x <= 1){
        return x;
    }
    int left = 1, right = x - 1;
    int ans;
    while(left <= right){
        long long int mid = left + (right - left) / 2;
        if(mid * mid == x){
            return mid;
        }
        if(mid * mid < x){
            left = mid + 1;
            ans = mid;
        }else{
            right = mid - 1;
        }
    }
    return ans;
}
