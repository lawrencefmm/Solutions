#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	int sum = 0;
	int last = 0;

	int n;

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		last = a*i - sum;
		cout << last << " \n"[i == n];
		sum += last;
	}
}
