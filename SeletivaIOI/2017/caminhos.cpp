#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
#define int long long

typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int vis[maxn], min_len[maxn], n, m, k;
pi dist[maxn];
vector<pi> G[maxn];


void dijkstra()
{
	for(int i = 1; i <= n; i++)
	{
		dist[i] = {(1ll << 60), 0};
		vis[i] = 0;
	}

	priority_queue<pii, vector<pii>, greater<pii>> q;
	// {distancia, {vertice, min_arestas}}
	dist[1] = {0, 0};
	q.push({0, {1, 0}});

	while(!q.empty())
	{
		int a = q.top().second.first;
		q.pop();

		if(vis[a]) continue;
		vis[a] = true;

		for(auto u : G[a])
		{
			int b = u.first, w = u.second + k;
			if(dist[b].first > dist[a].first + w)
			{
				dist[b] = {dist[a].first + w, dist[a].second + 1};
				q.push({dist[b].first, {b, dist[b].second}});
			}
			else if(dist[b].first == dist[a].first + w)
			{
				if(dist[b].second > dist[a].second + 1)
				{
					dist[b].second = dist[a].second + 1;
					q.push({dist[b].first, {b, dist[b].second}});
				}
			}
		}
	}
}

void bfs()
{
	memset(vis, 0, sizeof(vis));
	memset(min_len, 0x3f3f3f3f, sizeof(min_len));
	min_len[1] = 0;
	queue<int> q;
	q.push(1);

	while(!q.empty())
	{
		int a = q.front();
		q.pop();

		vis[a] = true;

		for(auto u : G[a])
		{
			if(!vis[u.first])
			{
				if(min_len[u.first] > min_len[a] + 1)
				{
					min_len[u.first] = min_len[a] + 1;
					q.push(u.first);
				}
			}
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}

	int ini = 0, fim = 1e9;

	int last = k;

	while(ini <= fim)
	{
		k = (ini + fim)/2;

		if(k == last) break;

		last = k;

		//cout << k << "\n";

		dijkstra();
		bfs();

		bool check = true;

		for(int i = 1; i <= n; i++) if(dist[i].second != min_len[i]) check = false;

		if(check) fim = k;

		else ini = k + 1; 
	}

	if(k == (int)1e9 - 1) cout << -1 << "\n";
	else cout << k << "\n";
}