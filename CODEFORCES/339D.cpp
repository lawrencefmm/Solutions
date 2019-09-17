#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1 << 18) + 10;

#define LEFT (2*node)
#define RIGHT ((2*node) + 1)
#define MID ((l + r)/2)

int tree[3*MAXN], v[MAXN];

void build(int node, int l, int r, int val)
{
	if(l == r) tree[node] = v[l];

	else
	{
		build(LEFT, l, MID, val - 1);
		build(RIGHT, MID + 1, r, val - 1);

		if(val & 1) tree[node] = tree[LEFT] ^ tree[RIGHT];
		else tree[node] = tree[LEFT] | tree[RIGHT];
	}
}

void update(int node, int l, int r, int pos, int x, int val)
{
	if(l == r) tree[node] = x;

	else
	{
		if(pos <= MID) update(LEFT, l, MID, pos, x, val - 1);
		else update(RIGHT, MID + 1, r, pos, x, val - 1);

		if(val & 1) tree[node] = tree[LEFT] ^ tree[RIGHT];
		else tree[node] = tree[LEFT] | tree[RIGHT];
	}
}


int main()
{
	int n, m;

	cin >> n >> m;

	int maxId = (1 << n);

	for(int i = 1; i <= maxId; i++)
	{
		cin >> v[i];
	}

	build(1, 1, maxId, n + 1);

	while(m--)
	{
		int pos, x;
		cin >> pos >> x;

		update(1, 1, maxId, pos, x, n + 1);
		cout << tree[1] << "\n";
	}
}
