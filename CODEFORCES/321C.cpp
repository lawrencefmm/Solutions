#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n, block[maxn], sz[maxn], qtd_vertice, pai[maxn];

vector<int> G[maxn];
vector<int> lista;

void dfs(int x, int p)
{
	pai[x] = p;

	lista.push_back(x);

	sz[x] = 1;

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

	qtd_vertice = sz[x];

	int centro = x;

	for(auto u : lista)
	{
		bool ok = true;

		if(qtd_vertice - sz[u] > qtd_vertice / 2) ok = false;

		for(auto v : G[u])
		{
			if(v == pai[u] or block[v]) continue;

			if(sz[v] > qtd_vertice/2) ok = false;
		}

		//cout<<u<<" "<<ok<<"\n";

		if(ok) centro = u;
	}

	return centro;
}

vector<int> tree[maxn];
char ans[maxn];

int build(int x, int h)
{
	x = find_centroid(x);

	//return 0;

	//cout<<"ACHOUY "<<x<<" "<<h<<"\n";

	block[x] = true;

	ans[x] = 'A' + h;

	for(auto u : G[x])
	{
		if(block[u]) continue;

		int v = build(u, h + 1);

		tree[x].push_back(v);
		tree[v].push_back(x);
	}
	return x;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n;

	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	//cout << "deu BO\n";

	build(1, 0);

	//dfsct(1, -1);

	//cout << "deu BO\n";

	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << " \n"[i == n];
	}
}
