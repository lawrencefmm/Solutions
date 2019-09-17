#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;


	cin >> a >> b >> c;

	int x = a - b;

	if(abs(x) > c)
	{
		if(x < 0) cout << "-\n";
		else cout << "+\n";
	}
	else if(abs(x) < c)
	{
		cout << "?\n";
	}
	else if(c == 0 and x == 0)
	{
		cout << 0 << "\n";
	}
	else cout << "?\n";
}
