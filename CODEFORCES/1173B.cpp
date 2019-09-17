#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if(n == 2)
	{
		cout << 2 << "\n";
		cout << "1 1\n1 2\n";
	}
	else
	{
		int qt = (n + 1 + (n%2 == 0))/2;

		cout << qt << "\n";

		int pt = 0;
		for(int i = 1; i <= qt; i++)
		{
			if(pt == n) break;
			cout << 1 << " " << i << "\n";
			pt++;

			if(i == qt)
			{
				for(int j = 2; j <= qt; j++)
				{
					if(pt == n) break;
					cout << j << " " << qt << "\n";
					pt++;
				}
			}
		}
	}
}
