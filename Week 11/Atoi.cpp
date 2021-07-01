int Solution::atoi(const string A) {
    int i = 0;
    while(i < A.length() && A[i] == ' '){
        i++;
    }
    bool neg = false, pos = false;
    int n = A.length();
    string no = "";
    for(int k = i; k < n; k++){
        if(A[k] >= '0' && A[k] <= '9'){
            no += A[k];
        }else if(A[k] == '+'){
            pos = true;
            if(neg){
                return 0;
            }
            continue;
        }else if(A[k] == '-'){
            neg = true;
            if(pos){
                return 0;
            }
        }
        else{
            if(k == i)
                return 0;
            else{
                break;
            }
        }
    }
    int nn = no.length();
    long long int number = 0;
    for(int j = nn - 1; j >= 0; j--){
        number += (no[j] - '0') * pow(10, nn - j - 1);
        if(neg){
            if(-number < INT_MIN){
                return INT_MIN;
            }
        }
        if(number > INT_MAX){
            return INT_MAX;
        }        
    }
    if(neg){
        return -number;
    }
    return number;
}
