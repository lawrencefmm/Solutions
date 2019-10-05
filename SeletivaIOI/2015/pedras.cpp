#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
const int BK_SIZE = 320;

int v[MAXN], qt[MAXN], resp[MAXN], n, q;

int ans;
int aux[MAXN];

void compress()
{
	set<pair<int, int>> st;
	for(int i = 1; i <= n; i++)
	{
		st.insert({v[i], i});
	}

	int cont = 0, last = -1;
	auto at = st.begin();
	for(int i = 1; i <= n; i++, at++)
	{
		if(at->first != last) v[at->second] = ++cont, last = at->first;
		else v[at->second] = cont;
	}
}

struct query
{
	int l, r, bk, id;

	bool operator<(const query& rhs) const
	{
		if(bk == rhs.bk)
		{
			if(bk&1) return r > rhs.r;
			else return r < rhs.r;
		}
		else return bk < rhs.bk;
	}
} qr[MAXN];

void add(int pos)
{
	qt[v[pos]]++;

	aux[qt[v[pos]]]++;

	if(qt[v[pos]] > ans) ans++;
}

void rem(int pos)
{

	aux[qt[v[pos]]]--;

	if(aux[qt[v[pos]]] == 0) ans--;

	qt[v[pos]]--;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> v[i];

	compress();

	for(int i = 0; i < q; i++)
	{
		cin >> qr[i].l >> qr[i].r;
		qr[i].id = i;
		qr[i].bk = qr[i].l/BK_SIZE;
	}

	sort(qr, qr + q);
	int cl = 1, cr = 0;

	for(int i = 0; i < q; i++)
	{
		int l = qr[i].l, r = qr[i].r;

		while(cr < r) add(++cr);
		while(cl > l) add(--cl);
		while(cr > r) rem(cr--);
		while(cl < l) rem(cl++);

		resp[qr[i].id] = ans;
	}

	for(int i = 0; i < q; i++)
	{
		cout << resp[i] << "\n";
	}
}