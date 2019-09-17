#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

#pragma GCC optimize("Ofast")

const int sz = 400;

int n, cp[maxn], q, tree[maxn];

vector<pair<int, int> > v;

//long long C(int i, int j);

struct query
{
	int l, r, id, bk;

	bool operator<(query const& rhs)
	{
		if(bk == rhs.bk)
		{
			return r < rhs.r;
		}
		return bk < rhs.bk;
	}
} qr[maxn];

inline int sum(const int &a)
{
	int ans = 0;

	for(int i = a; i > 0; i -= (i&-i))
		ans += tree[i];

	return ans;
}

inline void update(const int &p, const int &val)
{
	for(int i = p; i <= n; i += (i&-i))
	{
		tree[i] += val;
	}
}

inline bool cmp(const pair<int, int> &a,const pair<int, int> &b)
{
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}


int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		v.push_back({a, i});
	}

	sort(v.begin(), v.end(), cmp);

	long long cont = 0;
	for(int i = 0; i < n; i++){
		cp[v[i].second] = ++cont;
	}

	cin >> q;

	for(int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		qr[i].l = a, qr[i].r = b, qr[i].id = i, qr[i].bk = qr[i].l / sz;
	}

	sort(qr + 1, qr + 1 + q);

	int cr = 0, cl = 1;

	ll count = 0;

	int64_t ans[maxn];

	for(int i = 1; i <= q; i++)
	{
		int l = qr[i].l;
		int r = qr[i].r;

		while(cl > l)
		{
			cl--;
			count += sum(cp[cl] - 1);
			update(cp[cl], 1);
		}
		while(cl < l)
		{
			count -= sum(cp[cl] - 1);
			update(cp[cl], -1);
			cl++;
		}
		while(cr > r)
		{
			count -= cr - cl + 1 - (sum(cp[cr]));
			update(cp[cr], -1);
			cr--;
		}
		while(cr < r)
		{
			cr++;
			count += cr - cl - sum(cp[cr]);
			update(cp[cr], 1);
		}

		ans[qr[i].id] = count;
	}

	for(int i = 1; i <= q; i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}
