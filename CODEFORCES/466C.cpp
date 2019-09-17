#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;


int n, v[maxn];

vector<int> pref, suf;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;


	long long soma = 0;
	for(int i  = 0; i < n; i++)
	{
		cin >> v[i];
		soma += v[i];
	}
	if(soma % 3 != 0 or n < 3)
	{
		cout << 0 << "\n";
		return 0;
	}

	long long t = 0;
	for(int i = 0; i < n; i++)
	{
		t += v[i];
		if(t == soma / 3)
			pref.push_back(i);
	}
	t = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		t += v[i];
		if(t ==  soma / 3)
			suf.push_back(i);
	}

	sort(suf.begin(), suf.end());

	long long ans = 0;
	for(auto u : pref)
	{
		auto it = suf.end() - upper_bound(suf.begin(), suf.end(), u + 1);
		ans += it;
	}

	cout << ans << "\n";
	return 0;
}#include <bits/stdc++.h>
using namespace std;



int main()
{
	set<int> b;
	vector<int> a;
	int n , m;
	cin >> n >> m;
	for(int i  = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}

	for(int i  = 0; i < m ; i++)
	{
		int t;
		cin >> t;
		b.insert(t);
	}

	vector<int> ans;
	for(auto i : a)
	{
		if(b.count(i))
		{
			ans.push_back(i);
		}
	}
	for(auto u : ans)
	{
		cout << u << " ";
	}
	cout << "\n";
}
