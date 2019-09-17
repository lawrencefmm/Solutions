#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 20, MAXM  = (1 << 18) + 10, INF = (1 << 30);

ll n, m;
ll mat[MAXN][MAXN], dp[MAXM][MAXN];

ll solve(ll bitmask, ll v)
{

	if(v == n - 1) return dp[bitmask][v] = 0;

	if(dp[bitmask][v] != -1) return dp[bitmask][v];

	ll ans = 0;

	for(ll i = 0; i < n; i++)
	{
		if(bitmask & (1 << i) or !mat[v][i]) continue;

		ans = max(ans, solve((bitmask | (1 << i)), i) + mat[v][i]);

	}

	if(ans == 0) return dp[bitmask][v] = (-INF);

	return dp[bitmask][v] = ans;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m;

	while(m--)
	{
		ll a, b, w;
		cin >> a >> b >> w;
		mat[a][b] = max(mat[a][b], w);
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(1, 0) << "\n";


}
