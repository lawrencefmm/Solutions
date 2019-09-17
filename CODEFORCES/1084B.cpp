#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[1010];
ll n, s;

int main()
{

	cin >> n >> s;

	ll sum = 0;


	ll mini = 1e9;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];

		mini= min(mini, v[i]);
		sum += v[i];
	}

	if(sum < s)
	{
		cout << -1 << "\n";
		return 0;
	}

	int ans = mini;
	sum = 0;

	for(int i = 0; i < n; i++)
	{
		if(v[i] > mini) sum += v[i] - mini;
	}

	while(sum < s)
	{
		ans--;
		sum += n;
	}

	cout << ans << "\n";
}
