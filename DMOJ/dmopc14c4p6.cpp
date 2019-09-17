#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;

int f[maxn], g[maxn], pai[maxn];
vector<int> G[maxn];
vector<int> ch[maxn];

int dfs(int x, int p)
{
	pai[x] = p;
	int maior = 0;

	for(auto u : G[x])
	{
		if(u == p) continue;
		maior = max(maior, 1 + dfs(u, x));
		ch[x].push_back(f[u]);
	}
	return f[x] = maior;
}

int solve(int x)
{
	if(x == 1) return 0;

	if(g[x] != -1) return g[x];

	int maior = solve(pai[x]) + 1;

	if(ch[pai[x]].size() > 0)
	{
		if(ch[pai[x]][ch[pai[x]].size() - 1] == f[x])
		{
			ch[pai[x]].pop_back();
			if(ch[pai[x]].size() > 0) maior = max(maior, 2 + ch[pai[x]][ch[pai[x]].size() - 1]);
			ch[pai[x]].push_back(f[x]);
		}
		else
		{
			maior = max(maior,2 + ch[pai[x]][ch[pai[x]].size() - 1]);
		}
	}

	return g[x] = maior;
}

int main()
{
	//ios::sync_with_stdio(false), cin.tie(nullptr);

	int n;
	cin >> n;

	memset(g, -1, sizeof(g));

	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	f[1] = dfs(1, 0);

	for(int i = 1; i <= n; i++) sort(ch[i].begin(), ch[i].end());

	for(int i = 1; i <= n; i++)
	{
		//cout << f[i] << "\n";
		cout << 1 + max(f[i], solve(i)) << "\n";
		//cout << i << ": " << f[i] << " " << solve(i) << " " << pai[i] << " \n";
	}
}
