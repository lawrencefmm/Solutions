#include <bits/stdc++.h>
using namespace std;


int main()
{
	int q;
	cin >> q;

	while(q--)
	{
		int l, r, d;
		cin >> l >> r >> d;

		int ans = d;

		if(ans >= l and ans <= r)
		{
			ans = r + 1;
			if(ans % d) ans += d - ans % d;
		}

		cout << ans << "\n";
	}
}
