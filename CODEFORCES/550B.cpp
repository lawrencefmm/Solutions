#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 15) - 1;
const int inf = 1e9 + 10;


int n, l , r, x;
int v[20];
long long resp;
int main()
{
	ios::sync_with_stdio(false), cin.tie();

	cin >> n >> l >> r >> x;
	for(int i = 0; i < n; i++)
		cin >> v[i];

	for(int mask = 0; mask <= (1 << n) - 1; mask++)
	{
		long long s = 0;
		int m = 0;
		int mn = inf;
		for(int i = 0; i < n; i++)
		{
			if(mask & (1 << i))
			{
				s += v[i];
				m = max(m, v[i]);
				mn = min(mn, v[i]);
			}
		}

		if(s >= l and s <= r and (m - mn) >= x) resp++;

	}
	cout << resp << "\n";
	return 0;
}
