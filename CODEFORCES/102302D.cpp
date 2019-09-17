#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;

	cin >> a >> b;

	int j = 0;

	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] == b[j]) j++;
	}

	if(j == b.size()) cout << "YES\n";
	else cout << "NO\n";
}
