#include <bits/stdc++.h>
#include"factories.h"
using namespace std;
typedef int_fast64_t ll;
 
#pragma GCC optimize ("unroll-loops")
 
const int maxn  = 5e5 + 10, maxlog = 19;
 
int pai[maxn], h[maxn], block[maxn], sz[maxn], last[maxn];
ll ans[maxn];
ll dist[maxn][maxlog];
vector<pair<int, int>> G[maxn]; 
vector<int> tree[maxn], lista;
 
void dfs(int x, int p)
{
	pai[x] = p;
 
	sz[x] = 1;
 
	lista.push_back(x);
 
	for(auto u : G[x])
	{
		int v = u.first;
		if(block[v] or v == p) continue;
 
		dfs(v, x);
 
		sz[x] += sz[v];
	}
}
 
void find_dist(int v, int p, ll depht)
{
	dist[v][h[v]++] = depht;
 
	for(auto u : G[v])
	{
		if(u.first == p or block[u.first]) continue;
 
		find_dist(u.first, v, depht + u.second);
	}
}
 
int find_centroid(int x)
{
	lista.clear();
 
	dfs(x, x);
 
	int centro = x;
 
	int qt = sz[x];
 
	for(auto u : lista)
	{
		bool ok = true;
 
		if(qt - sz[u] > qt/2){ok = false; continue;}
 
		for(auto v : G[u])
		{
			int at = v.first;
 
			if(block[at] or pai[u] == at) continue;
 
			if(sz[at] > qt/2) {ok = false; break;};
		}
 
		if(ok) centro = u;
	}
 
	find_dist(centro, -1, 0);
 
	return centro;
}
 
int build(int x)
{
	x = find_centroid(x);
 
	block[x] = true;
 
	for(auto u : G[x])
	{
		int at = u.first;
		if(block[at]) continue;
 
		int v = build(at);
 
		tree[x].push_back(v);
		tree[v].push_back(x);
	}
 
	return x;
}
 
void init(int x, int p)
{
	pai[x] = p;
 
	for(auto u : tree[x])
	{
		if(u == p) continue;
		init(u, x);
	}
}
 
void Init(int N, int A[], int B[], int D[])
{
	for(int i = 0; i < N - 1; i++)
	{ 
		G[A[i]].push_back({B[i], D[i]});
		G[B[i]].push_back({A[i], D[i]});
	}
 
	int ct = build(1);
 
	init(ct, -1);
 
	for(int i = 0; i < maxn; i++) ans[i] = (long long)1e17;
}
 
int it;
 
long long Query(int S, int X[], int T, int Y[])
{
	it++;
	for(int i = 0; i < S; i++)
	{
		int v = X[i];
 
		int x = v;
 
		for(int j = h[x] - 1; j >= 0; j--)
		{
			if(last[v] != it)
			{
				last[v] = it;
				ans[v] = dist[x][j];
			}
			else ans[v] = min(ans[v], dist[x][j]);
			v = pai[v];
 		}
	}
 
	ll resp = 1e16;
 
	for(int i = 0; i < T; i++)
	{
		int v = Y[i];
 
		int x = v;
 
		for(int j = h[x] - 1; j >= 0; j--)
		{
			if(last[v] == it) resp = min(resp, ans[v] + dist[x][j]);
			v = pai[v];
		}
	}
	return resp;
}