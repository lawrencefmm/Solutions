#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, maxlog = 18;

int n, m, pai[maxn], sz[maxn], qt, block[maxn], dist[maxn];

vector<int> G[maxn], lista, tree[maxn];


void connect(int x, int y)
{
	tree[x].push_back(y);
	tree[y].push_back(x);
}

void dfs(int x, int p)
{
	pai[x] = p;

	sz[x] = 1;

	lista.push_back(x);

	for(auto u : G[x])
	{
		if(block[u] or u == p) continue;

		dfs(u, x);

		sz[x] += sz[u];
	}
}

int find_centroid(int x)
{
	lista.clear();

	dfs(x, x);

	qt = sz[x];

	int centro = x;

	for(auto u : lista)
	{
		bool ok = true;

		if(qt - sz[u] > qt/2) ok = false;

		for(auto v : G[u])
		{
			if(v == pai[u] or block[v]) continue;
			if(sz[v] > qt/2) ok = false;
		}
		if(ok) centro = u;
	}

	return centro;
}

int build(int x)
{
	x = find_centroid(x);

	block[x] = true;

	for(auto u : G[x])
	{
		if(block[u]) continue;

		int v = build(u);

		connect(v, x);
	}
	return x;
}

int h[maxn], anc[maxn][20];

void ancestor(int x, int p)
{
	h[x] = h[p] + 1;
	for(auto u : G[x])
	{
		if(u == p) continue;

		anc[u][0] = x;

		for(int i = 1; i <= maxlog; i++)
			anc[u][i] = anc[anc[u][i - 1]][i - 1];

		ancestor(u, x);
	}
}

int lca(int x, int y)
{
	if(x == y) return x;

	if(h[x] > h[y]) swap(x, y);

	for(int i = maxlog; i >= 0 and h[x] != h[y]; i--)
		if(h[y] - (1 << i) >= h[x])
			y = anc[y][i];

	if(x == y) return x;

	for(int i = maxlog; i >= 0; i--)
		if(anc[x][i] != anc[y][i] and anc[x][i] != 0 and anc[y][i] != 0)
			x = anc[x][i], y = anc[y][i];

	if(x == y) return x;
	return anc[x][0];
}

void find(int x, int p)
{
	pai[x] = p;

	for(auto u : tree[x])
	{
		if(u == p) continue;
		find(u, x);
	}
}

int main()
{
	//ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int x = build(1);
	find(x, 0);

	//cout << x << "\n\n\n";
	ancestor(1, 0);

	//cout << "fudeu\n";


	for(int i = 2; i <= n; i++) dist[i] = 1e9;

	int a = 1;

	while(a)
	{
		int LCA = lca(a, 1);
		dist[a] = h[1] + h[a] - 2*h[LCA];
		a = pai[a];
	}

	while(m--)
	{
		int q, node;
		cin >> q >> node;

		if(q == 1)
		{
			int t = node;

			while(t != 0)
			{
				int LCA = lca(t, node);

				dist[t] = min(dist[t], h[node] + h[t] - 2*h[LCA]);

				t = pai[t];
			}
		}
		else
		{
			int t = node;
			int distancia = 1e9;
			while(t != 0)
			{
				int LCA = lca(t, node);

				distancia = min(distancia, dist[t] - 2*h[LCA] + h[t] + h[node]);
				//if(dist[t] != 1e9) continue;
				t = pai[t];
			}

			cout << distancia << "\n";
		}
	}

}
