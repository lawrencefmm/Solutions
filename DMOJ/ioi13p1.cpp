#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

vector<int> comp[MAXN];
vector<pair<int, int>> G[MAXN];
bool vis[MAXN];
int dist[MAXN], pai[MAXN], maior, vert, diametro;

void makeComp(int a, int p, int cont)
{
	queue<pair<int, int>> q;
	q.push({a, p});

	while(!q.empty())
	{
		int x = q.front().first;
		int last = q.front().second;
		q.pop();

		vis[x] = true;
		comp[cont].push_back(x);

		for(auto u : G[x])
		{
			if(u.second == last) continue;
			q.push({u.second, x});
		}
	}
}

void dfs(int a, int p)
{
	queue<pair<int, int>> q;
	q.push({a, p});

	while(!q.empty())
	{
		int x = q.front().first;
		int last = q.front().second;
		q.pop();

		pai[x] = last;

		if(dist[x] > maior)
		{
			maior = dist[x];
			vert = x;
		}

		for(int i = 0; i < G[x].size(); i++)
		{
			pair<int, int> u = G[x][i];
			if(u.second == last) continue;
			dist[u.second] = dist[x] + u.first;
			q.push({u.second, x});
		}
	}
}

int travelTime(int N, int M, int L, int A[], int B[], int T[])
{

	for(int i = 0; i < M; i++)
	{
		G[A[i]].push_back({T[i], B[i]});
		G[B[i]].push_back({T[i], A[i]});
	}

	int cont = 0;

	for(int i = 0; i < N; i++)
	{
		if(!vis[i])
		{
			makeComp(i, i, ++cont);
		}
	}
	vector<int> maxDist;

	for(int i = 1; i <= cont; i++)
	{
		maior = 0, vert = comp[i][0], dist[comp[i][0]] = 0;
		dfs(comp[i][0], -1);

		maior = 0, dist[vert] = 0;
		dfs(vert, -1);

		diametro = max(diametro, maior);

		int ans = 1e9;

		int at = vert;
		while(at != -1)
		{
			ans = min(ans, max(maior - dist[at], dist[at]));
			at = pai[at];
		}
		maxDist.push_back(ans);
	}

	sort(maxDist.begin(), maxDist.end());
	reverse(maxDist.begin(), maxDist.end());


	if(maxDist.size() >= 2)
	{
		diametro = max(diametro, maxDist[0] + maxDist[1] + L);
	}
	if(maxDist.size() >= 3)
	{
		diametro = max(diametro, maxDist[1] + maxDist[2] + 2*L);
	}

	return diametro;
}