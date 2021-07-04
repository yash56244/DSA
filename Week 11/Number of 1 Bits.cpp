int setBits(int N) {
    int ans = 0;
    for(int i = 0; i < 32; i++){
        if(N & (1 << i)){
            ans++;
        }
    }
    return ans;
}
