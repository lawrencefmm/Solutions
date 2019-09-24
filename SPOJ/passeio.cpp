#include <bits/stdc++.h>
using namespace std;

const int maxn = 160;
int h[maxn], vis[maxn];
int dist[maxn];
vector<int> G[maxn];

int ans = 0;

void dfs(int x, int d)
{
	//cout << x << " " << d << "\n";
	dist[x] = d;
	ans = max(ans, d);
	for(int u : G[x])
	{
		if(h[x] > h[u] and d + 1 > dist[u]) dfs(u, d + 1);
	}
}

int main()
{
	int p, l, i;
	int cont = 0;

	while(cin >> p >> l >> i)
	{
		if(p == 0 and l == 0 and i == 0) break;

		memset(vis, 0, sizeof(vis));
		memset(dist, 0, sizeof(dist));

		for(int i = 1; i <= p; i++)
		{
			cin >> h[i];
			G[i].clear();
		}

		for(int i = 0; i < l; i++)
		{
			int a, b;
			cin >> a >> b;
			G[a].push_back(b);
		}

		ans = 0;
		dfs(i, 0);
		cout << "Teste " << ++cont << "\n";
		cout << ans << "\n\n";
	}

}