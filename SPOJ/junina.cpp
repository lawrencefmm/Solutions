#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, cont = 0;
	while(cin >> n)
	{
		if(n == 0) break;
		vector<int> G[30];
		for(int i = 1; i <= n; i++)
		{
			while(true)
			{
				int a;
				cin >> a;
				if(a == 0) break;
				G[i].push_back(a);
			}
		}

		int ans = 0;

		for(int mask = 0; mask < (1 << n); mask++)
		{
			bool flag = false;
			for(int i = 0; i < 20; i++)
			{
				if(flag) break;
				if(mask & (1 << i))
				{
					for(int u : G[i + 1])
					{
						if(flag) break;
						if(mask & (1 << (u - 1)))
						{
							flag = true;
							break;
						}
					}
				}
			}
			if(!flag) ans = max(ans, __builtin_popcount(mask));
		}
		cout << "Teste " << ++cont << "\n";
		cout << ans << "\n\n";
	}
}