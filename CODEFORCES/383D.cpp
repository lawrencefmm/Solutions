#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, maxn = 20202;
const int s = 10010;

int n, dp[2][maxn], v[1010];

int main()
{
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	int ans = 0;

	int old = 0, now = 1;
	dp[now][s] = 1;

	for(int i = 1; i <= n; i++){
		swap(old, now);
		for(int j = v[i]; j < maxn - v[i]; j++){
			dp[now][j] = dp[old][j-v[i]];
			dp[now][j] += dp[old][j+v[i]];
			dp[now][j] += (j == s);
			dp[now][j] %= mod;
		}
		ans += (dp[now][s] - 1);
		ans %= mod;
	}
	cout << ans << "\n";

}
