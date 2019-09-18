#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
#define x first
#define y second

typedef pair<int, int> pii;

int n, m, dist[maxn],fin[maxn];
bool vis[maxn];
vector<pii> G[maxn];

void dijkstra(int x)
{
	for(int i = 0; i <= maxn; i++) dist[i] = 1e9;
	for(int i = 0; i <= maxn; i++) vis[i]  = false;
	dist[x] = 0;

	priority_queue<pii> q;
	q.push({0, x});

	while(!q.empty())
	{
		int a = q.top().y;
		q.pop();

		if(vis[a]) continue;
		vis[a] = true;

		for(auto u : G[a])
		{
			int b = u.x, w = u.y;

			if(dist[a] + w < dist[b])
			{
				dist[b] = dist[a] + w;
				q.push({-dist[b], b});
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	dijkstra(0);
	for(int i = 0; i < n; i++)
	{
		fin[i] += dist[i];
	}
	dijkstra(n - 1);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		fin[i] += dist[i];
		ans = max(ans, fin[i]);
	}

	cout << ans << "\n";

}
