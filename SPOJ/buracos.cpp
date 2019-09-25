#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 10;

int vis[MAXN], cc, n, m;
vector<int> G[2][MAXN];

stack<int> q;
int scc[MAXN];

void dfs1(int x)
{
	vis[x] = true;
	for(int u : G[0][x]) if(!vis[u]) dfs1(u);
	q.push(x);
}

void dfs2(int x, int cc)
{
	scc[x] = cc;
	for(auto u : G[1][x]) if(!scc[u]) dfs2(u, cc);
}

void kosaraju()
{
	cc = 0;
	for(int i = 1; i <= n; i++) if(!vis[i]) dfs1(i);

	while(!q.empty())
	{
		int a = q.top();
		q.pop();
		if(!scc[a]) dfs2(a, ++cc);
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t = 0;

	while(cin >> n >> m)
	{
		if(n == 0 and m == 0) break;
		
		cout << "Teste " << ++t << "\n";
	
		for(int i = 1; i <= n; i++) G[0][i].clear(), G[1][i].clear();
		memset(vis, 0, sizeof(vis));
		memset(scc, 0, sizeof(scc));		
		bool ok = true;

		for(int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			G[0][a].push_back(b);
			G[1][b].push_back(a);
		}

		kosaraju();

		if(cc != 1) ok = false;

		if(!ok) cout << "N\n\n";
		else cout << "S\n\n";
	}
}