#include <bits/stdc++.h>
using namespace std;
#define L (2*no)
#define R ((2*no)  + 1)
#define m ((l + r) / 2)
#define int long long

const int32_t maxn = ((1ull << 23) + 10000);
const unsigned int inf = (1ull << 63) + 10000;

int v[maxn], tree[2*maxn];
int n, d;

int op(int a, int b){ return a < b ? a : b; }

void update(int no, int l, int r, int idx, int val)
{
	if(idx < l or idx > r) return;
	if(l == r)
	{
		tree[no] = val;
		return;
	}

	if(idx <= m) update(L, l, m, idx, val);
	else if(idx > m) update(R, m + 1, r, idx, val);

	tree[no] = op(tree[L], tree[R]);

}

int query(int no, int l, int r, int a, int b)
{
	if(b < l or a > r) return inf;

	if(r <= b and a <= l) return tree[no];

	if(b <= m) return query(L, l, m, a, b);
	if(a > m) return query(R, m + 1, r, a, b);

	return op(query(L, l, m, a , b), query(R, m + 1, r, a , b));

}

int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> d;

	for(int i = 1; i <= n; i++)
		cin >> v[i];

	update(1, 0, n + 1, 0, 0);
	for(int i = 1; i <= n + 1; i++)
	{
		int t = i - d;
		if(t < 0) t = 0;
		int q = query(1, 0, n + 1, t, i - 1);
		update(1, 0, n + 1, i, v[i] + q);
	}

	int t = query(1, 0, n + 1, n + 1, n + 1);
	cout << t << "\n";

	vector<int> ans;
	int pos;

	for(int i = n; i >= 1; i--){
		if(query(1, 0, n + 1, i, i) == t){
			ans.push_back(i);
			pos = i;
			break;
		}
	}
	for(int i = n; i >= 1; i--)
	{
		if(t == query(1, 0, n + 1, i, i) + v[pos]){
			ans.push_back(i);
			pos = i;
			t = query(1, 0, n + 1, i, i);
		}
	}

	for(int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
}
