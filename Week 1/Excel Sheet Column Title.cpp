#include<bits/stdc++.h>

using namespace std;

string convertToTitle(int n) {
    string ans;
    while(n != 0){
        int m = n % 26;
        if(m == 0)
            m = 26;
        ans += char(m + 64);
        n -= m;
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
	int n = 123;
	cout << convertToTitle(n);
	return 0;
}
