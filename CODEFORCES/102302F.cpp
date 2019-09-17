#include <bits/stdc++.h>
using namespace std;

int main()
{
	double n;

	cin >> n;

	double ans = 0;

	for(int i = 1; i <= (int)n; i++)
	{
		ans += 1.0*i/(n);
	}

	cout << fixed << setprecision(9) << ans << "\n";
}
