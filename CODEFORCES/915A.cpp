#include <bits/stdc++.h>
using namespace std;

int n, m;
int buck[101];

int main()
{
	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if(m % temp == 0)
		{
			ans = max(ans, temp);
		}
	}
	cout << (m/ans) << "\n";
}
