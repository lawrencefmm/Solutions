#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const int inf = 1e9 + 10;

int v[maxn], ans[maxn];
int bit[maxn];

int query(int x)
{
	int ans = inf;

	for(int i = x; i < maxn; i += i&-i)
	{
		ans = min(ans, bit[i]);
	}

	return ans;
}

void update(int x, int id)
{
	for(int i = x; i > 0; i -= i&-i)
	{
		bit[i] = min(bit[i], id);
	}
}

int main()
{
	int n;

	for(int i = 0; i < maxn; i++) bit[i] = inf;

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}


	for(int i = n; i >= 1; i--)
	{
		int x = query(v[i] + 1);
		//cout << x << "\n";

		if(x > i+v[i])
		{
			if(i+v[i] <= n) ans[i] = v[i];
			else ans[i] = n-i;
		}
		else ans[i] = x-i-1;


		update(v[i], i);
		//cout << query(1, 1, n, v[i], v[i] + i) << "\n";
	}

	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << " \n"[i == n];
	}


}
