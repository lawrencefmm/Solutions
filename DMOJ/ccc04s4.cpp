#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lli long long int
#define ulli long long unsigned
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

int d, n;
int tacos[35];
int memo[35][6000];

int solve(int id, int distancia) {
	if(id == n)
		return memo[id][distancia] = (distancia == 0) ? 0 : LINF;
	if(distancia < 0) return LINF;

	if(memo[id][distancia] == -1)
		return memo[id][distancia] = min(1 + solve(id, distancia - tacos[id]), solve(id + 1, distancia));

	return memo[id][distancia];
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(memo, -1, sizeof memo);
	cin >> d >> n;

	for(int i = 0; i < n; i++) {
		cin >> tacos[i];
	}

	int ans = solve(0, d);
	if(ans == LINF)
		cout << "Roberta acknowledges defeat.\n";
	else cout << "Roberta wins in " << ans << " strokes.\n";

	return 0;
}
