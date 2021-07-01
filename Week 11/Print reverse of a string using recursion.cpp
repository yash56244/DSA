#include <bits/stdc++.h>
using namespace std;

void reverse(string str, int i)
{
	if(str.size() == i)
	{
		return;
	}
	reverse(str, i + 1);
	cout << str[i];
}

int main()
{
	string a = "Geeks for Geeks";
	reverse(a, 0);
	return 0;
}
