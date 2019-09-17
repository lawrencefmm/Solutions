#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, mod = 1e9 + 7;
typedef long long ll;

ll dp[maxn], n, v[maxn];

bool comp(ll a, ll b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n;

	dp[0] = 1;

	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];

		vector<ll> div;

		for(int j = 1; j*j <= v[i]; j++)
		{
			if(v[i] % j == 0)
			{
				div.push_back(j);
				if(j != v[i]/j)
				{
					div.push_back(v[i]/j);
				}
			}
		}
		sort(div.begin(), div.end(), comp);

		for(auto u : div)
		{
			dp[u] = (dp[u] + dp[u - 1])%mod;
		}
	}

	ll ans = 0;

	for(int i = 1; i <= n; i++)
	{
		ans += dp[i];
	}
	ans %= mod;

	cout << ans << "\n";
}
