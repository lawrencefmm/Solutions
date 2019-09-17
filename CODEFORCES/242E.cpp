#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const int MAXN = 1e5 + 10;
const int MAX_BITS = 20;

#define LEFT (2*node)
#define RIGHT ((2*node) + 1)
#define MID ((l + r)/2)

ll tree[MAX_BITS][4*MAXN], lazy[MAX_BITS][4*MAXN];
ll v[MAXN];

void flush(int bit, int node, int l, int r)
{
	if(lazy[bit][node] == 0) return;

	else
	{
		tree[bit][node] = ((ll)(r - l + 1ll) - tree[bit][node]);
		if(LEFT < 4*MAXN) lazy[bit][LEFT] ^= 1;
		if(RIGHT < 4*MAXN) lazy[bit][RIGHT] ^= 1;
		lazy[bit][node] = 0ll;
	}
}

void build(int bit, int node, int l, int r)
{
	if(l == r) tree[bit][node] = ((v[l] & (1 << bit)) > 0);

	else
	{
		build(bit, LEFT, l, MID);
		build(bit, RIGHT, MID + 1, r);

		tree[bit][node] = tree[bit][LEFT] + tree[bit][RIGHT];
	}
}

ll query(int bit, int node, int l, int r, int a, int b)
{
	flush(bit, node, l, r);

	if(l > b || a > r) return 0;

	if(a <= l and r <= b) return tree[bit][node];

	else
	{
		if(b <= MID) return query(bit, LEFT, l, MID, a, b);
		if(a > MID) return query(bit, RIGHT, MID + 1, r, a, b);

		return (query(bit, LEFT, l, MID, a, b) + query(bit, RIGHT, MID + 1, r, a, b));
	}

}

void update(int bit, int node, int l, int r, int a, int b, int x)
{
	if(x == 0) return;
	flush(bit, node, l, r);

	if(l > b || a > r) return;

	if(a <= l and r <= b)
	{
		lazy[bit][node] ^= x;
		flush(bit, node, l, r);
	}
	else
	{
		update(bit, LEFT, l, MID, a, b, x);

		update(bit, RIGHT, MID + 1, r, a, b, x);

		tree[bit][node] = tree[bit][LEFT] + tree[bit][RIGHT];
	}
}

int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	for(int i = 0; i < MAX_BITS; i++)
	{
		build(i, 1, 1, n);
	}

	cin >> m;

	while(m--)
	{
		int op, a, b;

		cin >> op >> a >> b;

		if(op == 1)
		{
			ll ans = 0;

			for(ll i = 0; i < MAX_BITS; i++)
			{
				ans += (ll)(1ll << i)*query(i, 1, 1, n, a, b);
			}

			cout << ans << "\n";
		}
		else
		{
			ll x;
			cin >> x;

			for(ll i = 0; i < MAX_BITS; i++)
			{
				ll bit = (ll)((x & (1ll << (i))) > 0ll);
				update(i, 1, 1, n, a, b, bit);
			}
		}
	}
}
