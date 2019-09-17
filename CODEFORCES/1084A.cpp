#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;

	int n;

	cin >> n;


	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		v.push_back(a);
	}

	int ans =  1e9;

	for(int i = 0; i <= n; i++)
	{
		int eletricity = 0;

		for(int j = 0; j < n; j++)
		{
			if(v[j] == 0) continue;

			eletricity += j*2*(abs(v[j] - i) + v[j] + i);
		}

		ans = min(ans, eletricity);
	}

	cout << ans << "\n";
}
