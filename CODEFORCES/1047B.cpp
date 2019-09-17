#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

struct point
{
	int x, y;
}p[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;

	for(int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
		ans = max(ans, p[i].x + p[i].y);
	}
	cout << ans << "\n";
}
