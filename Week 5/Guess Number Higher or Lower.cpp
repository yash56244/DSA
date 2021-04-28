/* We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:

    -1: The number I picked is lower than your guess (i.e. pick < num).
    1: The number I picked is higher than your guess (i.e. pick > num).
    0: The number I picked is equal to your guess (i.e. pick == num).

Return the number that I picked. */
int guessNumber(int n) {
    int l = 1, r = n;
    while(l <= r){
        int m = l + (r - l) / 2;
        int i = guess(m);
        if(i == 0){
            return m;
        }
        if(i > 0){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    return -1;
}
