#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int v[maxn], bit[maxn], l[maxn], n;

void compress()
{
	set<pair<int, int> > s;
	for(int i = 1; i <= n; i++)
		s.insert({v[i], i});

	auto it = s.begin();

	for(int i = 1; i <= n; i++, it++)
		v[it -> second] = i;
}

void upd(int pos, int val)
{
	for(int i = pos; i <= n; i += i&-i)
	{
		bit[i] += val;
	}
}

int64_t get(int pos)
{
	int64_t ans = 0;
	for(int i = pos; i > 0; i -= i&-i)
		ans += bit[i];

	return ans;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> v[i];

	compress();

	int64_t ans = 0;
	for(int i = 1; i <= n; i++)
	{
		l[i] = get(n) - get(v[i]);
		upd(v[i], 1);
	}
	memset(bit, 0, sizeof(bit));
	for(int i = n; i >= 1; i--)
	{
		//cout << l[i] << " " << get(v[i]) << "\n";
		ans += 1ll*(l[i])*(get(v[i]));
		upd(v[i], 1);
	}

	cout << ans << "\n";

}
