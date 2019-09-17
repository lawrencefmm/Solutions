#include <bits/stdc++.h>
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
