#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;


	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	//for(auto u : v) cout << u << " ";

	int cont = 0;

	for(int i = 0; i < n - 1; i+=2)
	{
		if(v[i] != v[i + 1]) cont += abs(v[i] - v[i + 1]);
	}

	cout << cont << "\n";
}
