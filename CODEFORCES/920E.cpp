#include <bits/stdc++.h>
using namespace std;
 
unordered_set<int> lista;
set<pair<int, int>> edge;
int mark[200010];
 
vector<int> cp;
int sz = 0;
 
void bfs(int x)
{
	queue<int> q;
	q.push(x);
 
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		
		if(mark[a]) continue;
		mark[a] = true;
		sz++;

 
 		vector<int> aux;
		for(int u : lista)
		{
			if(edge.find({u, a}) != edge.end())  continue;
			q.push(u);
			aux.push_back(u);
		}
		for(auto u : aux) lista.erase(u); 
	}
}
 
int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
 
	for(int i = 1; i <= n; i++)
	{
		lista.insert(i);
	}
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		edge.insert({a, b}), edge.insert({b, a});
	}
 
	while(lista.size())
	{
		sz = 0;
		bfs(*lista.begin());
		cp.push_back(sz);
	}
 
	sort(cp.begin(), cp.end());
 
	cout << cp.size() << "\n";
 
	for(int u : cp)
	{
		cout << u << " ";
	}
	cout << "\n";
}