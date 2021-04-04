#include<bits/stdc++.h>

using namespace std;

int titleToNumber(string s) {
    int n = s.length();
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        int m = s[i] - 'A' + 1;
        ans += pow(26, n - i - 1) * m;
    }
    return ans;
}

int main(){
	string s = "ABC";
	cout << titleToNumber(s);
	return 0;
}
