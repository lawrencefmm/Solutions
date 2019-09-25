#include <bits/stdc++.h>
using namespace std;


const int MAXN = 410;

vector<int> G[MAXN];
int mark[MAXN], cont = 0, n, m;


void dfs(int x)
{
	// cout << x << "\n";
	mark[x] = true;
	cont++;
	for(int u : G[x]) if(!mark[u]) dfs(u);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int teste = 0;

	while(cin >> n >> m)
	{
		if(n == 0 and m == 0) break;
		for(int i = 1; i <= n; i++) G[i].clear();

		if(n == 1)
		{
			cout << "Teste " << ++teste << "\n";
			cout << "nenhum\n\n";
			continue;
		}

		for(int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		vector<int> lista;
		
		for(int i = 1; i <= n; i++)
		{
			memset(mark, 0, sizeof(mark));
			mark[i] = true;
			cont = 1;
			// cout << i << " : \n";
			dfs(G[i][0]);
			if(cont != n) lista.push_back(i);
			// cout << cont << "\n\n";
		}

		cout << "Teste " << ++teste << "\n";
		if((int)lista.size() == 0) cout << "nenhum";
		else for(int ans : lista) cout << ans << " ";
		cout << "\n\n";
	}
}