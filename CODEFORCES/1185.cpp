#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll maxn = (1 << 15) + 10;

ll dp[maxn][4][225];

int n, k, d[20], g[20];

ll solve(int mask, int gen, int t)
{
	if(t == k) return 1;
	if(t > k) return 0;


	if(__builtin_popcount(mask) == n and t != k) return 0;

	if(dp[mask][gen][t] != -1) return dp[mask][gen][t];

	//cout << mask << " " << gen << " " << t << "\n";

	ll ans = 0;

	for(int i = 0; i < n; i++)
	{
		//cout << i << "\n";
		if(g[i] == gen) continue;

		if((mask & (1 << i)) == 0)
		{
			ans = (ans + solve(mask ^ (1 << i), g[i], t + d[i]))%mod;
			//cout << "chamou\n";
		}
	}

	return dp[mask][gen][t] = ans;
}

int main()
{
	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> d[i] >> g[i];


	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0, 0) << "\n";
}
