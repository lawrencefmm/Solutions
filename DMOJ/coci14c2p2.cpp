#include <bits/stdc++.h>
using namespace std;

int main()
{
	multiset<string> s;

	int n;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string temp;

		cin >> temp;

		s.insert(temp);
	}

	for(int i = 0; i < n - 1; i++)
	{
		string t;

		cin >> t;

		auto u = s.find(t);
		s.erase(u);
	}

	for(auto u : s)
	{
		cout << u << "\n";
	}
}
