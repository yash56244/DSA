#include <bits/stdc++.h>
using namespace std;

void permute(string a, int l)
{
	if (l == a.size())
		cout << a << endl;
	else
	{
		for (int i = l; i < a.size(); i++)
		{
			swap(a[l], a[i]);
			permute(a, l + 1);
			swap(a[l], a[i]);
		}
	}
}

int main()
{
	string str = "ABC";
	int n = str.size();
	permute(str, 0);
	return 0;
}
