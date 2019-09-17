#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int64_t s, a, b, c;
		cin >> s >> a >> b >> c;

		int64_t ans = s/c;
		int64_t p = (ans/a)*b + ans;
		cout << p << "\n";
	}
}
