unsigned int getFirstSetBit(int n)
{
    if(n == 0){
        return 0;
    }
    unsigned int ans = 0;
    for(int i = 0; i < 32; i++){
        if(n & (1 << i)){
            if(ans == 0){
                return i + 1;
            }
        }
    }
    return -1;
}
