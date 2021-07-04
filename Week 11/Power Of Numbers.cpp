long long power(int n, int r)
{
    if(r == 0){
        return 1;
    }
    long long ans = power(n, r / 2);
    ans = ((ans % mod) * (ans % mod)) % mod;
    if(r & 1){
        ans = ((ans % mod) * (n % mod)) % mod;
    }
    return ans;
}
