#include <bits/stdc++.h>
using namespace std;
#define int uint_fast32_t

const int maxn = 21, mod = 1e9 + 7;

#pragma GCC optimize ("Ofast")

int dp[maxn][1 << maxn], mat[maxn][maxn];
int n;

int solve(int i, int mask)
{
	if(i == n)
	{
		if(mask == (1 << n) - 1) return 1;
		else return 0;
	}

	if(dp[i][mask] != -1) return dp[i][mask];

	int ans = 0;

	for(int j = 0; j < n; j++)
	{
		if((mask & (1 << j)) or !mat[i][j]) continue;

		ans += solve(i + 1, (mask | (1 << j))) % mod;
	}

	return dp[i][mask] = ans % mod;
}


int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0) << "\n";
}
