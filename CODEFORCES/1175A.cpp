#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int a, b;

		cin >> a >> b;

		int cont = 0;

		while(a)
		{
			if(a < b)
			{
				cont += a;
				break;
			}
			if(a % b)
			{
				cont += (a % b);
			}
			a /= b;
			cont++;
		}

		cout << cont << "\n";
	}
}
