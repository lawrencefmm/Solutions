#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;

typedef long long ll;
typedef pair<ll, ll> pii;
#define ff first
#define ss second

ll pai[maxn], w[maxn], pref[maxn];
vector<pii> G[maxn];

vector<tuple<char, ll, ll>> qr;

bool vis[maxn];

void dfs(int x, int y)
{
	if(vis[x] == true) return;
	vis[x] = true;

	for(auto u : G[x])
	{
		if(u.ff == y) continue;
		if(u.ff >= x) pref[u.ff] = pref[x] + u.ss;
		else pref[u.ff] = pref[x] - u.ss;
		dfs(u.ff, x);
	}
}

int find(int x)
{
	if(x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
	a = find(a), b = find(b);
	
	if(a == b) return;

	if(w[a] < w[b]) swap(a, b);

	pai[b] = a;
	w[a] += w[a];
}

int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	for(int i = 0; i < maxn; i++)
	{
		pai[i] = i;
		w[i] = 1;
	}

	int n, q;

	cin >> n >> q;

	while(q--)
	{
		char op;
		int i, j;
		cin >> op >> i >> j;

		if(op == 'L')
		{
			int x;
			cin >> x;

			G[i - 1].push_back({j, x});
			G[j].push_back({i - 1, x});

		}
		
		qr.push_back(make_tuple(op, i, j));
	}

	for(int i = 0; i <= n; i++)
		dfs(i,i);

	for(auto u : qr)
	{
		int i = get<1>(u), j = get<2>(u);
		if(get<0>(u) == 'L')
		{
			join(i - 1, j);
		}
		else
		{
			if(find(i - 1) == find(j))
			{
				cout << pref[j] - pref[i - 1] << "\n";
			}
			else cout << "Esquecido\n";
		}

	}
}