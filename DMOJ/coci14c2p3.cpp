#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 10;

int n, k;

int main()
{

	cin >> n >> k;

	vector<int> p;

	int v[maxn];
	deque<pair<int, int>> tm;

	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		tm.push_back({a, i});
	}

	sort(tm.begin(), tm.end());

	for(int i = 0; i < n; i++)
	{
		int at = (i)/k + 1;

		v[tm[i].second] = at;
	}

	int dp[maxn];

	for(int j = 0; j < n; j++)
	{
		dp[j] = 1;
		for(int i = 0; i < j; i++)
		{
			if(v[i] <= v[j])
			{
				dp[j] = max(dp[j],dp[i]+1);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, dp[i]);


	cout << n - ans << "\n";
}
