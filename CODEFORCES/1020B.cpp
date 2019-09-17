#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, v[maxn];
bool vis[maxn];

int dfs(int x)
{
	if(vis[x] == true) return x;
	vis[x] = true;
	return dfs(v[x]);
}


int main()
{
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	for(int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		cout << dfs(i) << "\n";
	}
}
 
