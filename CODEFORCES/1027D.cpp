#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e5 + 10;

int n;
int vis[maxn], a[maxn], grau[maxn], grau2[maxn], c[maxn];
vector<int> G[maxn];

int resp;

int minCycle(int x, int path)
{
	//cout << x << " " << path << "\n";
	vis[x] = true;

	int ans = min(c[x], path);

	if(!vis[a[x]]) ans = min(ans, minCycle(a[x], ans));

	return c[x] = ans;
}

int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int b;
		cin >> b;

		a[i] = b;
		grau[b]++;
		G[b].push_back(i);
	}

	queue<int> q;

	for(int i = 1; i <= n; i++) if(!grau[i]) q.push(i);

	while(!q.empty())
	{

		int u = q.front();
		q.pop();
		//cout << u << " ";
		grau[a[u]]--;
		if(!grau[a[u]]) q.push(a[u]);
	}

	//cout << "\n";

	//cout << grau[2] << "\n";

	for(int i = 1; i <= n; i++)
	{
		if(grau[i] > 0 and !vis[i])
		{
			resp += minCycle(i, c[i]);
		}
	}

	//for(int i = 1; i <= n; i++) if(grau[i]) dfs(i, c[i]);

	cout << resp << "\n";

}
// 6
// 1 7 5 1 10 11
// 2 3 2 2 6 5
