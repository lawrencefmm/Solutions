#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	queue<int> gm, bl;

	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		gm.push(a);
	}

	for(int i = 1; i <= m; i++)
	{
		int a;
		cin >> a;
		bl.push(a);
	}
	int cont = 0;
	while(!gm.empty())
	{
		int a = gm.front(), b = bl.front();
		gm.pop();
		if(a <= b)
		{
			bl.pop();
			cont++;
		}
		if(bl.size() == 0) break;
	}
	cout << cont << "\n";
}
