// Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, 
// find the smallest element in the list that is larger than the given target.
// Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'. 
char nextGreatestLetter(vector<char>& letters, char target) {
    int l = 0, h = letters.size() - 1;
    while(l <= h){
        int m = l + (h - l) / 2;
        if(target >= letters[m]){
            l = m + 1;
        }else{
            h = m - 1;
        }
    }
    return letters[l % letters.size()];
}
