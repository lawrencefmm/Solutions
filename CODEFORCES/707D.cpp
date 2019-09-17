#include <bits/stdc++.h>
using namespace std;

#define MID ((l + r)/2)
const int MAXM = 1e3 + 1;
int n, m, q;

struct node
{
	bitset<MAXM> shelf;
	bool inv;
	int sum;

	node *left;
	node *right;

	node()
	{
		for(int i = 0; i < MAXM; i++) shelf[i] = false;
		sum = inv = 0;
		left = right = nullptr;
	}
};

void update(node* prev, node* cur, int pos, int val, int op, int l, int r)
{
	if(l == r)
	{
		cur->sum += prev->sum;
		cur->inv += prev->inv;
		for(int i = 0; i < MAXM; i++) cur->shelf[i] = prev->shelf[i];

		if(op == 1)
		{
			if(!cur->inv && !cur->shelf[val]) cur->shelf[val]=true, cur->sum++;
			if(cur->inv && cur->shelf[val]) cur->shelf[val]=false, cur->sum++;
		}
		else if(op == 2)
		{
			if(!cur->inv && cur->shelf[val]) cur->shelf[val]=false, cur->sum--;
			if(cur->inv && !cur->shelf[val]) cur->shelf[val]=true, cur->sum--;
		}
		else if(op == 3)
		{
			cur->inv = 1 - cur->inv;
			cur->sum = m - cur->sum;
		}
	}
	else
	{
		if(prev->right == nullptr) prev->right = new node();
		if(prev->left == nullptr) prev->left = new node();

		if(pos <= MID)
		{
			cur->right = prev->right;

			cur->left = new node();

			update(prev->left, cur->left, pos, val, op, l, MID);
		}
		else
		{
			cur->left = prev->left;

			cur->right = new node();

			update(prev->right, cur->right, pos, val, op, MID + 1, r);
		}

		cur->sum = cur->left->sum + cur->right->sum;
	}
}

node* ver[100010];

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m >> q;

	node* root = new node();
	ver[0] = root;

	for(int a = 1; a <= q; a++)
	{
		int op, i;
		cin >> op >> i;

		node* at = new node();

		if(op == 1 or op == 2)
		{
			int j;
			cin >> j;

			update(ver[a - 1], at, i, j, op, 1, n);
		}
		else if(op == 3)
		{
			update(ver[a - 1], at, i, i, op, 1, n);
		}
		else
		{
			at = ver[i];
		}

		ver[a] = at;
		cout << at->sum << '\n';
	}
}
