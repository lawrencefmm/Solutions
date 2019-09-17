#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;

pair<int, int> p;
int n, v[maxn], sum[maxn], k, ans;

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> k;

	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}

	for(int i = 1; i <= n; i++)
	{
		int ini = i, fim = n, best = -1;

		while(ini <= fim)
		{
			int mid = (ini + fim) / 2;

			if(sum[mid] - sum[i - 1] + k >= mid - i + 1)
			{
				ini = mid + 1;
				best = mid;
			}
			else fim = mid - 1;
		}
		if(best != -1 and best - i + 1 >= ans)
		{
			ans = best - i + 1;
			p.first = i;
			p.second = best;
		}
	}

	cout << ans << "\n";
	for(int i = p.first; i <= p.second; i++) v[i] = 1;

	for(int i = 1; i <= n; i++) cout << v[i] << " \n"[i == n];

}
