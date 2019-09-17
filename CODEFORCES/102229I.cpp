#include <bits/stdc++.h>
using namespace std;


#define int long long
const int maxn = 1e5 + 10;

int n;
unordered_map<int, int> dp[maxn];

struct play
{
	int p, f;

	bool operator<(const play& rhs) const
	{
		return f < rhs.f || (f == rhs.f && p < rhs.p);
	}
} pl[maxn];

int solve(int x, int y)
{
	if(x == n - 1)
	{
		return y - pl[x].f;
	}

	if(dp[x].find(y) != dp[x].end()) return dp[x][y];

	int para = y - pl[x].f;
	int continua = solve(x + 1, y + pl[x + 1].p);

	return dp[x][y] = max(para, continua);
}


int32_t main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> pl[i].p >> pl[i].f;
	}

	sort(pl, pl + n);
	cout << solve(0, pl[0].p) << "\n";
}
