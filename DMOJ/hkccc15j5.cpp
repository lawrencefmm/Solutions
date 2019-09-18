#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

int cor[maxn], pr[maxn], br[maxn], dp[maxn][maxn], cp[maxn];
int n, m, comp;
vector<int> G[maxn];

void coloring(int x)
{
	cor[x] = 0;
	br[comp]++;
	vector<int> q;
	q.push_back(x);

	for(int i = 0; i < (int)q.size();i++)
	{
		int v = q[i];

		for(auto u : G[v])
		{
			if(cor[u] == -1)
			{
				cp[u] = cp[x];
				cor[u] = 1 - cor[v];
				if(cor[u]) pr[comp]++;
				else br[comp]++;
				q.push_back(u);
			}
		}
	}
}

bool bk[maxn];

bool check()
{
	for(int i = 1; i <= n; i++)
	{
		if(cor[i] == -1){
			comp++;
			cp[i] = comp;
			coloring(i);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(auto v : G[i]){
			if(cor[i] == cor[v]) return false;
		}
	}

	return true;
}

int solve(int i, int p, int b)
{
	if(i == comp + 1) return abs(p - b);

	if(dp[i][p] != -1) return dp[i][p];

	int pp = p + br[i], bb = b + pr[i];
	int pl = p + pr[i], bl = b + br[i];

	return dp[i][p] = min(solve(i + 1, pp, bb), solve(i + 1, pl, bl));
}

void back(int i, int p, int b)
{
	if(i == comp + 1) return;

	int pp = p + br[i], bb = b + pr[i];
	int pl = p + pr[i], bl = b + br[i];

	if(dp[i][p] == solve(i + 1, pp, bb))
	{
		bk[i] = 1;
		back(i + 1, pp, pp);
	}
	else back(i + 1, pl, bl);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m;
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(cor, -1, sizeof(cor));
	memset(dp, -1, sizeof(dp));
	if(check())
	{
		solve(1, 0, 0);
		back(1, 0, 0);

		for(int i = 1; i <= n; i++)
		{
			if(bk[cp[i]])
			{
				if(cor[i]) cout << 2;
				else cout << 1;
			}
			else
			{
				if(cor[i]) cout << 1;
				else cout << 2;
			}
		}
		return 0;
	}

	cout << -1 << "\n";
}
