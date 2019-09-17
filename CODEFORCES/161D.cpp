#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 10;
const int MAXK = 5e2 + 10;

template<typename T>
void print(const T& a, string end = "\n")
{
	cout << a << end;
}


int dist[MAXN][MAXK];
int n, k;
vector<int> G[MAXN];

long long ans = 0;

void solve(int x, int p)
{

	dist[x][0] = 1;

	for(int u : G[x])
	{
		if(u == p) continue;

		solve(u, x);


		for(int d = 0; d < k; d++)
		{
			dist[x][d + 1] += dist[u][d];
		}
	}

	for(int u : G[x])
	{
		if(u == p) continue;

		for(int d = 1; d < k; d++)
		{
			ans += (dist[x][k - d] - dist[u][k - d - 1]) * dist[u][d - 1];
		}
	}
}



int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> k;

	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	solve(1, 0);


	// for(int i = 1; i <= n; i++)
 // 	{
 // 		cout << i << " : ";
 // 		for(int j = 1; j <= k; j++)
 // 			cout << dist[i][j] << ", ";
 // 		cout << "\n";
 // 	}
	ans /= 2ll;
	for(int i = 1; i <= n; i++) ans += dist[i][k];
	cout << ans << "\n";
}
