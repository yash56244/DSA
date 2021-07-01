#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
	int count[26] = {0};
	for (int i = 0; i < str.length(); i++) {
		count[str[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		if(count[i] > 1){
			char c = 'a' + i;
			cout<<c<<" appears "<<count[i]<<" times."<<endl;
		}
	}
}
int main()
{
	string str = "test string";
	printDups(str);
	return 0;
}

