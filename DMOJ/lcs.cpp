#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int s1[maxn], s2[maxn], n, m, dp[maxn][maxn];

int lcs(int a , int b)
{

	if(dp[a][b] != -1) return dp[a][b];

	if(a == 0 or b == 0) return dp[a][b] = 0;

	if(s1[a] == s2[b]) return lcs(a-1,b-1)+1;

	return dp[a][b] = max(lcs(a-1, b), lcs(a, b-1));

}


int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> s1[i];

	for(int i = 1; i <= m; i++)
		cin >> s2[i];

	int c = lcs(n, m);

	//cout << n - c << " " << m - c << "\n";
	cout << c;
}
