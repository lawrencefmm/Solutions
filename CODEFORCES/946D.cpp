#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
typedef long long ll;

int n, m, k;

ll dp[maxn][maxn];
ll c[maxn][maxn];
char s[maxn][maxn];

vector<ll> sz[maxn];



void build()
{

	for(int dia = 0; dia < n; dia++)
	{
		for(int i = 0; i < m; i++)
		{
			if(s[dia][i] == '1') sz[dia].push_back(i);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if((int)sz[i].size() == 0)
		{
			for(int j = 0; j <= k; j++)
				c[i][j] = 0;
		}
		if((int)sz[i].size() == 1)
		{
			c[i][0] = 1;
			for(int j = 1; j <= k; j++)
				c[i][j] = 0;
		}
	}

	for(int dia = 0; dia < n; dia++)
	{
		for(int i = 0; i < (int)sz[dia].size(); i++)
		{
			for(int j = (int)sz[dia].size() - 1; j >= 0; j--)
			{
				int p = (int)sz[dia].size() - j + i - 1;
				if(p == (int)sz[dia].size())
				{
					c[dia][p] = 0;
				}
				if(i > j) break;
				c[dia][p] = min(c[dia][p], sz[dia][j] - sz[dia][i] + 1ll);
			}
		}
	}
}


long long solve(int dia, int p)
{
	if(dia == n) return 0;
	if(p < 0) return 1e9;
	if(dp[dia][p] != -1) return dp[dia][p];
	if(p == 0)	return dp[dia][p] = c[dia][p] + solve(dia + 1, p);

	ll ans = 2e9;
	for(int i = 0; i <= p; i++)
	{
		ans = min(ans, solve(dia + 1, p - i) + c[dia][i]);
	}

	return dp[dia][p] = ans;
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m >> k;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> s[i][j];


	ll tot = 0;
	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < maxn; i++)
	{
		for(int j = 0; j < maxn; j++)
		{
			c[i][j]= 1e9;
		}
	}

	build();

	for(int i = 0; i < n; i++) tot += (int)sz[i].size();

	if(tot <= k)
	{
		cout << 0 << "\n";
		return 0;
	}

	cout << solve(0, k) << "\n";
}
