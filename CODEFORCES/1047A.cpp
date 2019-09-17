#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a, b, c;

	cin >> n;

	if(n % 3 == 0)
	{
		a = b = 1;
		c = n - 2;
	}
	if(n % 3 == 1 or n % 3 ==  2)
	{
		a = 1;
		b = 2;
		c = n - 3;
	}

	cout << a << " " << b << " " << c << "\n";
	//cout << a + b + c << "\n";
}
