#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
#define L ((2*no))
#define R ((2*no) + 1)
#define m ((l + r)/2)

int vet[maxn];

struct tr
{
	int maxi = -1, mini = 1e9 + 1;

} tree[3*maxn];

tr nl;

tr op(tr a, tr b)
{
	tr c;
	c.maxi = max(a.maxi, b.maxi);
	c.mini = min(a.mini, b.mini);
	return c;
}

void build(int no, int l, int r)
{
	if(l == r)
	{
		tree[no].maxi = vet[l];
		tree[no].mini = vet[l];
		return;
	}

	build(L, l, m);
	build(R, m + 1, r);

	tree[no] = op(tree[L], tree[R]);
}

void update(int no, int l, int r, int idx, int val)
{
	if(l == r)
	{
		tree[no].maxi = val;
		tree[no].mini = val;
		return;
	}

	if(idx > r or idx < l) return;

	if(idx > m) update(R, m + 1, r, idx, val);

	if(idx <= m) update(L, l, m, idx, val);

	tree[no] = op(tree[L], tree[R]);
}

tr query(int no, int l, int r, int a, int b)
{
	if(b < l or a > r) return nl;

	if(r <= b and l >= a) return tree[no];

	return op(query(L, l, m, a, b), query(R, m + 1, r, a, b));
}

int n, v, c;

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> v >> c;


	for(int i = 1; i <= n; i++)
	{
		cin >> vet[i];
	}

	build(1, 1, n);
	int cont = 0;
	for(int i = 1; i <= n - v + 1; i++)
	{
		tr qr = query(1, 1, n, i, i + v - 1);

		if(qr.maxi - qr.mini <= c){
			cout << i << "\n";
			cont++;
		}

	}

	if(cont == 0)
	{
		cout << "NONE\n";
	}

}
