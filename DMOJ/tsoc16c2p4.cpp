#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

bool primo[maxn];
int n, m, dp[maxn][110];
vector<int> v, p;

void crivo()
{
	memset(primo, 1, sizeof(primo));
	primo[1] = 0;
	primo[0] = 0;

	for(int i = 2; i <= 100; i++)
		for(int j = i * i; j * j < maxn; j += i)
			primo[j] = 0;

	for(int i = 2; i <= n; i++)
		if(primo[i]) p.push_back(i);
}

bool solve(int dinheiro, int obj)
{
	if(dinheiro > n) return 0;

	if(obj == m){
		if(primo[dinheiro]) return true;

		else return false;
	}

	if(dp[dinheiro][obj] != -1) return dp[dinheiro][obj];

	for(auto i : p)
	{
		if(i > v[obj]) break;
		if(solve(dinheiro + i*v[obj], obj + 1)) return dp[dinheiro + i*v[obj]][obj + 1] = 1;
	}

	return dp[dinheiro][obj] = 0;
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	crivo();

	if(solve(0,0)) cout << "its primetime\n";

	else cout << "not primetime\n";

	return 0;
