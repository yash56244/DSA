long long int nthFibonacci(long long int n){
    if(n <= 2){
        return 1;
    }
    long long int a = 1, b = 1;
    for(int i = 2; i < n; i++){
        long long int temp = a;
        a = b;
        b = ((temp % mod) + (b % mod)) % mod;
    }
    return b;
}
