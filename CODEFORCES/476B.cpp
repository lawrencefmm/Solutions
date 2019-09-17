#include <bits/stdc++.h>
using namespace std;

int a, b, x, y, z;

long long fat(int x)
{
	int ans = 1;
	for(int i = 2; i <= x; i++)
		ans *= i;

	return ans;
}

int main()
{
	string s1 , s2;
	cin >> s1 >> s2;
	for(auto i: s1)
	{
		if(i == '+')
			a++;
		if(i == '-')
			b++;
	}
	for(auto i: s2)
	{
		if(i == '+')
			x++;
		if(i == '-')
			y++;
		if(i == '?')
			z++;
	}
	if(x > a or y > b)
	{
		cout << "0.000000000000\n";
		return 0;
	}
	else
	{
		int p = a - x;
		long double ans = fat(z)/(fat(p));
		ans /= fat(z-p);
		ans /= pow(2, z);
		cout << setprecision(12) << fixed << ans << "\n";
	}
}
