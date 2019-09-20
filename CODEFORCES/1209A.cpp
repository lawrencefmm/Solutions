#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int v[n + 10];

	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	int sz = n;
	int cont = 0;
	int mark[n + 10];
	memset(mark, 0, sizeof(mark));

	while(sz > 0)
	{
		cont++;
		int best = 0, num = 0;

		for(int val = 1; val <= n; val++)
		{
			int at = 0;
			if(mark[val]) continue;
			for(int i = 1; i <= n; i++)
			{
				if(mark[i] == true) continue;
				if(v[i]%v[val] == 0) at++;
			}
			if(at > best)
			{
				best = at;
				num = val;
			}
		}
		if(best == 1)
		{
			cont += (sz - 1);
			break;
		}
		for(int i = 1; i <= n; i++)
		{
			if(v[i]%v[num]==0) mark[i] = true;
		}
		sz -= best;
	}
	cout << cont << "\n";
}a
