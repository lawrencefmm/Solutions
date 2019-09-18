#include <bits/stdc++.h>
using namespace std;
#define left ((2*no))
#define right ((2*no) + 1)
#define mid ((l + r) / 2)
typedef long long ll;
const int maxn = 1e5 + 10;

int v[maxn];

inline int gcd(int a, int b)
{
	int t;
	while(b)
	{
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}

struct node
{
	int minimo = 1e9, mdc = 1, qtmin = 0;
}tree[3*maxn];

inline node op(node a, node b)
{
	node c;
	c.minimo = min(a.minimo, b.minimo);
	c.mdc = gcd(a.mdc, b.mdc);
	if(c.minimo == a.minimo) c.qtmin += a.qtmin;
	if(c.minimo == b.minimo) c.qtmin += b.qtmin;
	return c;
}

void build(int no, int l, int r)
{
	if(l == r)
	{
		tree[no].minimo = v[l];
		tree[no].qtmin = 1;
		tree[no].mdc = v[l];
		return;
	}

	build(left, l, mid);
	build(right, mid + 1, r);

	tree[no] = op(tree[left], tree[right]);
}


void update(int no, int l, int r, int val, int idx)
{
	if(l == r)
	{
		tree[no].minimo = tree[no].mdc = val;
		return;
	}

	if(idx <= mid) update(left, l, mid, val, idx);
	else update(right, mid + 1, r, val, idx);

	tree[no] = op(tree[left], tree[right]);
}

node query(int no, int l, int r, int a, int b)
{
	if(b >= r and l >= a) return tree[no];

	if(b <= mid) return query(left, l, mid, a , b);
	if(a > mid) return query(right, mid + 1, r, a, b);

	return op(query(left, l, mid, a , b), query(right, mid + 1, r, a, b));
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> v[i];

	build(1, 1, n);

	while(m--)
	{
		char op;
		int l, r;
		cin >> op >> l >> r;

		if(op == 'C')
		{
			update(1, 1, n, r, l);
			continue;
		}

		node qr = query(1, 1, n, l, r);
		if(op == 'M') cout << qr.minimo << "\n";
		else if(op == 'G') cout << qr.mdc << "\n";
		else
		{
			if(qr.minimo == qr.mdc) cout << qr.qtmin << "\n";
			else cout << 0 << "\n";
		}
	}
}
