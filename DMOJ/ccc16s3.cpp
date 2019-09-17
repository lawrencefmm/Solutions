#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int sz[maxn], h[maxn], mark[maxn];
vector<int> lista, G[maxn];
int n, m, ans = 0;


void find(int x, int p)
{
	h[x] = h[p] + 1;

	for(auto u : G[x])
	{
		if(u == p) continue;

		find(u, x);
	}
}

int find_diameter_node()
{
	int start = lista[0];

	find(start, start);

	int second, distSecond = 0;

	for(int i = 0; i < n; i++)
	{
		if(h[i] > distSecond and mark[i])
		{
			second = i;
			distSecond = h[i];
		}
	}

	h[second] = 0;
	find(second, second);

	int ans, distAns = 0;

	for(int i = 0; i < n; i++)
	{
		if(h[i] > distAns and mark[i])
		{
			ans = i;
			distAns = h[i];
		}
	}

	return ans;

}


void build(int x, int p)
{
	h[x] = h[p] + 1;
	if(mark[x]) sz[x]++;

	//cout << x << " ";

	for(int u : G[x])
	{
		if(u == p) continue;

		build(u, x);
		sz[x] += sz[u];
	}
}


void dfs(int x, int p)
{
	for(int u : G[x])
	{
		if(u == p) continue;

		if(sz[u] > 0) dfs(u, x), ans += 2;
	}
}

int main()
{
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		mark[a] = true;
		lista.push_back(a);
	}
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int start = find_diameter_node();

	//cout << start << "\n";

	h[start] = 0;
	build(start, start);
	dfs(start, start);

	//for(int i = 0; i < n; i++) cout << sz[i] << " \n"[i == n - 1];

	int max_dist = 0;
	for(int i = 0; i < n; i++)
	{
		if(mark[i])
		{
			max_dist = max(max_dist, h[i] - 1);
			//cout << max_dist << " " << i << "\n";
		}
	}

	//cout << ans << "\n";
	cout << ans - max_dist << "\n";


}
