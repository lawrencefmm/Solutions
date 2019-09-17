#include <bits/stdc++.h>
using namespace std;

bool teste(int x, int y, int h, int w)
{
	if(x <= h and y <= w) return true;
	//if(x <= w and y <= h) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int q;
	cin >> q;

	int x = 0, y = 0;

	while(q--)
	{
		char op;
		int h, w;
		cin >> op >> h >> w;
		if(w > h) swap(h, w);

		if(op == '+')
		{
			x = max(x, h);
			y = max(y, w);
		}
		else
		{
			if(teste(x, y, h, w)) cout << "YES\n";
			else cout << "NO\n";
		}

	}
}
