#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;

const int maxn = 5e4 + 10, inf = 1e9;

int dist[maxn], n, m;
vector<pair<int, pair<int, pair<int, int> > > > G[maxn];
bool vis[maxn];



int green(int a, int g, int r)
{
	if((a % (g + r)) < g) return 0;
	else return (g + r) - (a % (g + r));
}

void dijkstra()
{
	priority_queue<pii, vector<pii>, greater<pii> > q;
	for(int i = 1; i <= n; i++) dist[i] = inf;
	
	dist[1] = 0;
	q.push({0, 1});

	while(!q.empty())
	{
		int a = q.top().y;

		q.pop();

		if(vis[a]) continue;
		vis[a] = true;

		for(auto u : G[a])
		{
			int b = u.x, w = u.y.x, g = u.y.y.x, r = u.y.y.y;
			
			if(dist[a] + w + green(dist[a] + w, g, r) < dist[b])
			{
				dist[b] = dist[a] + w + green(dist[a] + w, g, r);
				q.push({dist[b], b});
			}
		}	
	}
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;

	for(int i = 1; i <= m; i++)
	{
		int a, b, w, g, r;
		cin >> a >> b >> w >> g >> r; 
		G[a].push_back({b, {w, {g, r}}});
	}

	dijkstra();

	if(dist[n] == inf)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << dist[n] << "\n";
		return 0;
	}



}