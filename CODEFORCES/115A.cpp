#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int h[maxn], n;
bool vis[maxn];

vector<int> G[maxn];

void dfs(int x)
{
	vis[x] = true;
	for(auto u : G[x])
		if(!vis[u])
		{
			h[u] = h[x] + 1;
			dfs(u);
		}
}
vector<int> sup;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if(a != -1)
			G[a].push_back(i);
		else
			sup.push_back(i);


	}
	int c = 0;

	for(auto c : sup)
	{
		h[c] = 1;
		dfs(c);
	}
	for(int i = 1; i <= n; i++)
		c = max(c, h[i]);


	cout << c << "\n";
}
