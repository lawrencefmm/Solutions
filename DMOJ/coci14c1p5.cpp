#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int MAXN = 1e6 + 10;
const int MAXM = 110;
const int MAXK = 510;

int dp[MAXM][MAXK], qt[MAXM], cost[MAXM][MAXK];
int n, m, k;

int sum(int total, int times)
{
    times++;
    int x = total/ times;
    int big = total % times;
    int small = times - big;
    return x* (x+1)/2*small + (x+1)*(x+2)/2*big;

}
int solve(int i, int j)
{
	if(i == m + 1) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int best = 1e9;

	for(int p = 0; p <= j; p++)
	{
		best = min(best, solve(i + 1, j - p) + cost[i][p]);
	}

	return dp[i][j] = best;
}

int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m >> k;

	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		qt[a]++;
	}

	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			cost[i][j] = sum(qt[i], j);
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(1, k);
}
