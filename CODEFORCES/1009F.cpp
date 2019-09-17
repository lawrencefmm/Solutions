#include <bits/stdc++.h>
using namespace std;
typedef uint_fast64_t ll;
const int maxn = 21;


ll n, m, k, cont = 0, mid;
ll mat[maxn][maxn];
unordered_map<ll, ll> tab[maxn][maxn];


void solve1(int x, int y, ll v, int cnt)
{
	if(x >= n or y >= m) return;

	v ^= mat[x][y];

	if(cnt == mid)
	{
		tab[x][y][v]++;
		return;
	}

	solve1(x + 1, y, v, cnt + 1);
	solve1(x, y + 1, v, cnt + 1);
}


void solve2(int x, int y, ll v, int cnt)
{
	if(x < 0 or y < 0) return;


	if(cnt == n + m - 2 - mid)
	{
		if(tab[x][y].count(v ^ k))
			cont += tab[x][y][v ^ k];
		return;
	}

	solve2(x - 1, y, v ^ mat[x][y], cnt + 1);
	solve2(x, y - 1, v ^ mat[x][y], cnt + 1);
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m >> k;
	mid = (n + m - 2) / 2;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mat[i][j];


	solve1(0, 0, 0, 0);

	solve2(n - 1, m - 1, 0, 0);

	cout << cont << "\n";

	return 0;

}
