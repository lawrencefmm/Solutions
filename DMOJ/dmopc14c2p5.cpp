#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1000;

int n, m, grau[maxn];
vector<int> G[maxn];
double pb[maxn];

void bfs()
{
	queue<int> q;
	q.push(1);

	while(!q.empty())
	{
		int a = q.front();
		q.pop();

		for(auto u : G[a])
		{
			pb[u] += (double)pb[a]/((double)G[a].size());
			q.push(u);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	while(m--)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		//grau[b]++;
	}
	pb[1] = 1.0;
	//bfs();
	cout << setprecision(12) << fixed;

	for(int i = 1; i <= n; i++)
	{
		double sz = G[i].size();
		for(auto u : G[i])
		{
			pb[u] += pb[i]/sz;
		}
	}


	for(int i = 1; i <= n; i++)
	{
		if((int)G[i].size() == 0) cout << pb[i] << "\n";
	}
}
