#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli long long unsigned
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

int bit[500005];
int n;

void att(int x, int val) {
	while(x <= n) {
		bit[x] += val;
		x += (x & -x);
	}
}

int soma(int x) {
	int ret = 0;

	while(x) {
		ret += bit[x];
		x -= (x & -x);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	int q, aux;

	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> aux;
		att(i, aux);
	}

	while(q--) {
		cin >> a >> b;
		int ans = soma(n);
		ans -= soma(b) - soma(a - 1);

		cout << ans << "\n";
	}

	return 0;
}
