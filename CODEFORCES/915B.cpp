#include <bits/stdc++.h>
using namespace std;
int n, pos, l, r;

int main()
{
	cin >> n >> pos >> l >> r;
	int cont = 0;

	if(l == 1 and r == n)
	{
		cout << "0\n";
		return 0;
	}
	if(pos <= l)
	{
		if(l == 1) cont--;
		if(r == n) cont -= r - l + 1;
		cont += l - pos + 1;
		cont += r - l + 1;
		cout << cont << "\n";
	}else if(pos >= r)
	{
		if(r == n) cont--;
		if(l == 1) cont -= r - l + 1;
		cont += pos - r + 1;
		cont += r - l + 1;
		cout << cont << "\n";
	}else
	{
		if(l == 1)
		{
			cont += r - pos + 1;
		}else if(r == n)
		{
			cont += pos - l	+ 1;
		}else
		{
			cont += min(pos - l, r - pos) + 1;
			cont += abs(l - r) + 1;
		}
		cout << cont << "\n";
	}

}
