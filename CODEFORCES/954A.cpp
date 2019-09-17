#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int cont = 0;

	for(int i = 0; i < n - 1; i++)
	{
		if(s[i] == 'U' and s[i + 1] == 'R')
		{
			cont++;
			i++;
			continue;
		}
		if(s[i] == 'R' and s[i + 1] == 'U')
		{
			cont++;
			i++;
		}
	}
	cout << n - cont<< "\n";
}
