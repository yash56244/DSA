class Solution {
public:
    int strStr(string &haystack, string &needle) {
        if(needle.length() > haystack.length())
            return -1;
        if(needle.length() == 0)
            return 0;
        for(int i = 0; i < haystack.length(); i++){
            if(haystack[i] == needle[0]){
                int j = 1, ii = i + 1;
                while(ii < haystack.length() && j < needle.length() && haystack[ii] == needle[j]){
                    ii++;
                    j++;
                }
                if(j == needle.length()){
                    return i;
                }
            }
        }
        return -1;
    }
};
