#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, k;
		cin >> n >> k;

		string s;

		for(int i = 0; i < n; i++)
		{
			s += 'a' + (26 + i)%k;
		}

		cout << s << "\n";
	}
}
