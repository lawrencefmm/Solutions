#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")

const int maxn = 410;
int n, v[maxn], pref[maxn];
bool dp[maxn][maxn];

int sum(int i, int j)
{
	return pref[j] - pref[i - 1];
}

int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pref[i] = pref[i - 1] + v[i];
	}

	for(int l = n; l >= 1; l--)
	{
		for(int r = 1; r <= n; r++)
		{
			if(l >= r)
			{
				dp[l][r] = true;
				continue;
			}

			int left = l, right = r;

			while(left < right)
			{
				if(sum(l, left) == sum(right, r) and dp[left + 1][right - 1]*dp[l][left]*dp[right][r])
				{
					dp[l][r] = true;
					break;
				}

				if(sum(l, left) > sum(right, r)) right--;

				else left++;
			}

			dp[l][r] = max(dp[l][r], false);
		}
	}

	int ans = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			ans = max(ans, dp[i][j]*(sum(i, j)));
		}
	}

	cout << ans << "\n";
}
