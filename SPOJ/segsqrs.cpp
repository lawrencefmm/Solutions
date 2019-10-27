#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
#define int long long

#define MID ((l + r)/2)
#define LEFT (2*node)
#define RIGHT ((2*node) + 1)

struct no
{
	int sum, sq;
};

no operator+(const no& a, const no& b)
{
	no ans;
	ans.sum = a.sum + b.sum;
	ans.sq = a.sq + b.sq;
	return ans;
}

no tree[4*MAXN];
int lazy1[8*MAXN], lazy2[8*MAXN];
int v[MAXN];

void flush(int node, int l, int r)
{
	if(lazy1[node] < 1001)
	{
		tree[node].sq += 2ll*tree[node].sum*lazy1[node] + 
			(r - l + 1)*(lazy1[node]*lazy1[node]);

		tree[node].sum += (r - l + 1)*lazy1[node];
	}
	if(lazy2[node] < 1001)
	{
		tree[node].sum = (r - l + 1)*lazy2[node];
		tree[node].sq = (r - l + 1)*lazy2[node]*lazy2[node];
	}
	if(l != r)
	{
		lazy1[LEFT] = lazy1[RIGHT] = lazy1[node];
		lazy2[LEFT] = lazy2[RIGHT] = lazy2[node];
	}
	lazy1[node] = lazy2[node] = 1001; 
}

void build(int node, int l, int r)
{
	if(l == r)
	{
		tree[node].sum = v[l];
		tree[node].sq = v[l]*v[l];
		return;
	}

	build(LEFT, l, MID);
	build(RIGHT, MID + 1, r);
	tree[node] = tree[LEFT] + tree[RIGHT];
}

int query(int node, int a, int b, int l, int r)
{
	flush(node, l, r);
	if(a <= l and r <= b) return tree[node].sq;

	if(b <= MID) return query(LEFT, a, b, l, MID);
	if(a > MID) return query(RIGHT, a, b, MID + 1, r);

	return query(LEFT, a, b, l, MID) + query(RIGHT, a, b, MID + 1, r);
}

void update(int node, int a, int b, int l, int r, int val, int type)
{
	//cout << a << " " << b << " " << l << " " << r << '\n';
	flush(node, l, r);

	if(r < a or l > b) return;

	if(a <= l and r <= b)
	{
		if(type) lazy1[node] = val;
		else lazy2[node] = val;
		flush(node, l, r);
		return;
	}

	update(LEFT, a, b, l, MID, val, type);
	update(RIGHT, a, b, MID + 1, r, val, type);

	tree[node] = tree[LEFT] + tree[RIGHT];
}


int32_t main()
{
	//ios::sync_with_stdio(false), cin.tie(nullptr);
	int t;
	cin >> t;

	for(int i = 1; i <= t; i++)
	{
		int n, q;
		cin >> n >> q;
		for(int i = 1; i <= n; i++) cin >> v[i];
		for(int i = 1; i < 4*MAXN; i++) lazy1[i] = lazy2[i] = 1001;

		build(1, 1, n);

		cout << "Case " << i << ":\n";

		while(q--)
		{
			int op;
			cin >> op;
			if(op == 2)
			{
				int l, r;
				cin >> l >> r;
				cout << query(1, l, r, 1, n) << "\n";
			}
			else
			{
				int l, r, val;
				cin >> l >> r >> val;
				update(1, l, r, 1, n, val, op);
			}
		}
	}
}