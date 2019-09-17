#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int dp[maxn][10], n, vit[maxn][3], c[maxn];

int solve(int obj, int mask)
{
	if(obj == n and mask != 7) return 1e8;
	if(mask == 7 or obj == n) return 0;
	if(dp[obj][mask] != -1) return dp[obj][mask];

	int nao_coloca = solve(obj + 1, mask);

	int mask2 = mask;

	for(int i = 0; i < 3; i++)
	{
		if(vit[obj][i])
		{
			mask2 |= (1 << i);
		}
	}

	int coloca = solve(obj + 1, mask2) + c[obj];

	return dp[obj][mask] = min(coloca, nao_coloca);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string t;
		cin >> c[i] >> t;
		for(auto u : t)
		{
			if(u == 'A') vit[i][0] = 1;
			if(u == 'B') vit[i][1] = 1;
			if(u == 'C') vit[i][2] = 1;
		}
	}

	memset(dp, -1, sizeof(dp));

	int t = solve(0,0);
	if(t >= 1e8) cout << -1 << "\n";
	else cout << t << "\n";
}
