#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define int long long
typedef pair<pair<int, int>, int> piii;
typedef pair<int, int> pii;
const int maxn = 1e4 + 10;

vector<piii> G[maxn];
int A, B, k, n, m, vis[maxn];
int dist[maxn][210];

void dijkstra(int ini)
{
	memset(dist, 0x3f3f3f3f, sizeof(dist));

	dist[ini][0] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> q;

	q.push({0,A});

	while(!q.empty())
	{
		auto a = q.top();

		q.pop();

		int at = a.y;

		vis[at] = false;

		for(auto u : G[at])
		{
			for(int i = 0; i + u.x.y < k; i++)
			{
				int tempo = dist[at][i] + u.x.x;

				if(tempo < dist[u.y][i + u.x.y])
				{
					dist[u.y][i + u.x.y] = tempo;
					if(!vis[u.y])
					{
						q.push({tempo, u.y});
						vis[u.y] = true;
					}
				}
			}

		}
	}
}


int32_t main()
{
	cin >> k >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a, b, t, h;
		cin >> a >> b >> t >> h;
		G[a].push_back({{t, h}, b});
		G[b].push_back({{t, h}, a});
	}

	cin >> A >> B;

	dijkstra(A);

	int fast = 0x3f3f3f3f;

	for(int i = 0; i < k; i++) fast = min(fast, dist[B][i]);

	cout << ((fast == (int)0x3f3f3f3f) ? -1 : fast)  << "\n";
}
