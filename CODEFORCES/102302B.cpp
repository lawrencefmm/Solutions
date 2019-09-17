#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main()
{
	int a, b;

	set<int> ans;

	cin >> a >> b;

	for(int i = 1; i*i <= a; i++)
	{
		if(a%i == 0 and i%b == 0)
		{
			ans.insert(i);

		}
		if(a%i == 0)
		{
			int aux = a/i;

			if(aux%b == 0) ans.insert(aux);
		}
	}

	//sort(ans.begin(), ans.end());

	for(auto u : ans) cout << u << " ";
	cout << "\n";
}
