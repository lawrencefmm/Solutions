#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t n, m;
	cin >> n >> m;

	int64_t p;

	for(int i = 1; i <= n; i++)
	{
		long long mult = int64_t(i)*(i - 1)/2;
		if(mult >= m)
		{
			p = i;
			break;
		}
	}

	if(m == 0ll)
	{
		cout << n << " " << n << "\n";
	}
	else
	{
		if(m >= n/2 + (n%2))
		{
			cout << 0 << " ";
		}
		else
		{
			cout << n - 2*m << " ";
		}

		cout << n - p << "\n";

	}

}
