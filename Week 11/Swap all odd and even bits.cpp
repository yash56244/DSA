unsigned int swapBits(unsigned int n)
{
    unsigned int ans = 0;
    vector<int> v(32, 0);
    for(int i = 0; i < 32; i++){
        if(n & (1 << i))
            v[i] = 1;
    }
    for(int i = 0; i < 31; i += 2){
        swap(v[i], v[i + 1]);
    }
    for(int i = 0; i < 32; i++){
        ans += (v[i] * (1 << i));
    }
    return ans;
}
