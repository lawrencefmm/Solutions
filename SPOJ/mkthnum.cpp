#include <bits/stdc++.h>
using namespace std;

#define MID ((l+r)/2)
const int MAXN = 1e5 + 10;

struct node
{
	int sz;

	node* left, *right;

	node()
	{
		sz = 0;
		left = right = nullptr;
	}
};

node* ver[MAXN];
unordered_map<int, int> mp;
int v[MAXN], n, q;

void compress()
{
	set<pair<int, int>> cp;
	for(int i = 1; i <= n; i++)
	{
		cp.insert({v[i], i});
	}

	auto at = cp.begin();

	for(int i = 1; i <= n; i++, at++)
	{
		v[at->second] = i;
		mp[i] = at->first;
	}
}

void update(node*prev, node*cur, int pos, int l, int r)
{
	if(l == r) cur->sz = 1;

	else
	{
		if(prev->right == nullptr) prev->right = new node();
		if(prev->left == nullptr) prev->left = new node();

		if(pos <= MID)
		{
			cur->right = prev->right;

			cur->left = new node();

			update(prev->left, cur->left, pos, l, MID);
		}
		else
		{
			cur->left = prev->left;

			cur->right = new node();

			update(prev->right, cur->right, pos, MID + 1, r);
		}

		cur->sz = cur->left->sz + cur->right->sz;
	}
}

int get(node* cur, int a, int b, int l, int r)
{
	if(a <= l and r <= b) return cur->sz;

	if(b <= MID) return get(cur->left, a, b, l , MID);
	else if(a > MID) return get(cur->right, a, b, MID + 1, r);

	return get(cur->left, a, b, l, MID) + get(cur->right, a, b, MID + 1, r);
}

int query(int a, int b, int k)
{
	int l = 1, r = n, ans;
	while(l < r)
	{
		if(get(ver[MID], a, b, 1, n) >= k) r = MID;

		else l = MID + 1;
	}

	return mp[l];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> q;

	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
		ver[i] = new node();
	}

	ver[0] = new node();

	compress();

	vector<pair<int, int>> ord;
	for(int i = 1; i <= n; i++)
	{
		ord.push_back({v[i], i});
	}

	sort(ord.begin(), ord.end());

	for(int i = 1; i <= n; i++)
	{
		update(ver[i - 1], ver[i], ord[i - 1].second, 1, n);
	}

	for(int i = 1; i <= q; i++)
	{
		int l, r, k;
		cin >> l >> r >> k;

		cout << query(l, r, k) << "\n";
	}


}
