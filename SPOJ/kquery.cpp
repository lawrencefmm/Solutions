#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define MID ((l + r)/2)
const int MAXN = 3e4 + 10;

struct node
{
    int sum;
    node* left, *right;

    node()
    {
        sum = 0;
        left = right = nullptr;
    }
};

int v[MAXN], n;
vector<int> ord[MAXN];
vector<pair<int, int>> idx;

void compress()
{
	pair<int, int> st[MAXN];
	for(int i = 1; i <= n; i++) st[i - 1] = {v[i], i};
	sort(st, st + n);
	int cnt = 0;

	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			v[st[i].second] = ++cnt;
		}
		else
		{
			if(st[i].first == st[i - 1].first) v[st[i].second] = v[st[i - 1].second];
			else v[st[i].second] = ++cnt;

		}
		idx.push_back({st[i].first, cnt});
		ord[v[st[i].second]].push_back(st[i].second);
	}
}

void update(node* prev, node* cur, int pos, int l, int r)
{
	if(l == r) cur->sum = 1;

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
		cur->sum = cur->left->sum + cur->right->sum;
	}
}

int query(node *cur, int a, int b, int l, int r)
{
	if(a <= l and r <= b) return cur->sum;
	if(cur->sum == 0) return 0;

	if(b <= MID) return query(cur->left, a, b, l, MID);
	else if(a > MID) return query(cur->right, a, b, MID + 1, r);

	return query(cur->left, a, b, l, MID) + query(cur->right, a, b, MID + 1, r);
}

inline int scan(){
	int p=0, x=gc(), s=1;
	for(;x<'0'||x>'9';x=gc()) if(x=='-') s=-1;
	for(;x>='0'&&x<='9';x=gc()) p = 10*p + x - '0';
	return p*s;
}

node* ver[MAXN];
bool mark[MAXN];

int32_t main()
{
	mt19937 rd(random_device{}());
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cout.tie(nullptr);

	n = scan();

	for(int i = 1; i <= n; i++) v[i] = scan();;
	compress();

	ver[0] = new node();

	int cnt = 0;
	for(int i = 0; i < idx.size(); i++)
	{
		for(auto pos : ord[idx[i].second])
		{
			if(mark[pos]) break;
			mark[pos] = true;

			ver[cnt + 1] = new node();
			update(ver[cnt], ver[cnt+1], pos, 1, n);
			cnt++;
		}
	}

	int q = scan();

	while(q--)
	{
		int a, b, k;
		a = scan(), b = scan(), k = scan();

		int l = 0, r = n;
		while(l < r)
		{
			if(idx[MID].first > k) r = MID;
			else l = MID + 1;
		}
		if(l == n) cout << 0 << '\n';
		else cout << (b - a + 1 - query(ver[l], a, b, 1, n)) << '\n';
	}

}
