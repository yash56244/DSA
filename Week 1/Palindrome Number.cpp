#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(int x) {
    long int ans = 0;
    int temp = x;
    while(x != 0)
    {
        ans = ans * 10 +  x%10;;
        x = x / 10;
    }    
    return (ans < INT_MIN || ans > INT_MAX || ans < 0 || ans != temp) ? false : true;
}

int main(){
	int n = 123;
	cout<<isPalindrome(n);
	return 0;
}
