int countBitsFlip(int a, int b){
    int diff = 0;
    for(int i = 0; i < 32; i++){
        if((a & (1 << i)) != (b & (1 << i))){
            diff++;
        }
    }
    return diff;
}
