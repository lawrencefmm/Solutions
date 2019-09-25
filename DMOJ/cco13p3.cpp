#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 4e5 + 10;

int n;
int h[maxn], dist1[maxn], grau[maxn];
vector<int> G[maxn];

void find(int x, int p)
{
	h[x] = h[p] + 1;

	for(auto u : G[x])
	{
		if(u == p) continue;

		find(u, x);
	}
}

int find_diameter()
{
	int start = 1, diameter = -1;

	h[start] = -1;
	find(start, start);

	int second, distSecond = 0;

	for(int i = 1; i <= n; i++)
	{
		if(h[i] > distSecond)
		{
			second = i;
			distSecond = h[i];
		}
	}

	h[second] = -1;
	find(second, second);

	int ans;

	for(int i = 1; i <= n; i++)
	{
		if(h[i] > diameter)
		{
			ans = i;
			diameter = h[i];
		}
	}
	return diameter;
}

int find_center()
{
	queue<int> q;

	for(int i = 1; i <= n; i++)
	{
		if(grau[i] == 1) q.push(i);
	}

	int vis = 0;

	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		vis++;

		if(vis == n) return a;

		for(int u : G[a])
		{
			grau[u]--;
			if(grau[u] == 1) q.push(u);
		}
	}
}

unordered_map<int, int> qt[maxn];
unordered_map<int, int> tot;

void dfs(int x, int p, int y, int height = 1)
{
	if(G[x].size() == 1) 
	{
		qt[y][height]++;
		tot[height]++;
		return;
	}

	for(int u : G[x])
	{
		if(u == p or u == y) continue;

		dfs(u, x, y, height + 1);
	}
}


void count(int center, int diameter)
{
	int ans = 0;
	int half = (diameter) / 2;
	int rest = (diameter) - half;

	cout << half << " " << rest << "\n";


	for(int u : G[center])
	{
		dfs(u, center, u);
	}

	for(int u : G[center])
	{
		ans += (tot[half] - qt[u][half])*qt[u][rest];
		ans += (tot[rest] - qt[u][rest])*qt[u][half];
	}

	ans /= 2;
	if(half == rest) ans /= 2;	

}


int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
		grau[a]++;
		grau[b]++;
	}

	int diameter = find_diameter();
	int ans = count(find_center(), diameter);

	cout << diameter + 1 << " " << ans << "\n";
}