#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, sq = 450;

int vet[sq][maxn];
int v[maxn], bloco[maxn];
int n, q;

vector<int> num[maxn];

void sivo()
{
	for(int i = 1; i < maxn - 1; i++)
		for(int j = i; j < maxn - 1; j += i)
			num[j].push_back(i);
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> q;

	sivo();
	int p = sqrt(n);
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
		bloco[i] = (int)(i / p);
		for(auto j : num[v[i]]) vet[bloco[i]][j]++;
	}

	while(q--)
	{
		int a;
		cin >> a;
		if(a == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			int ans = 0;
			if(bloco[r] - bloco[l] <= 1)
			{
				for(int i = l; i <= r; i++)
				{
					if(v[i] % x == 0) ans++;
				}
				cout << ans << "\n";
				continue;
			}

			for(int i = bloco[l] + 1; i < bloco[r]; i++)
				ans += vet[i][x];


			for(int i = l; bloco[i] == bloco[l]; i++)
			{
				if(v[i] % x == 0) ans++;
			}

			for(int i = r; bloco[i] == bloco[r]; i--)
			{
				if(v[i] % x == 0) ans++;
			}

			cout << ans << "\n";
		}
		else if(a == 2)
		{
			int u, val;
			cin >> u >> val;
			for(auto j : num[v[u]])
				vet[bloco[u]][j]--;

			v[u]= val;

			for(auto j : num[val])
				vet[bloco[u]][j]++;
		}
	}

	return 0;
}
