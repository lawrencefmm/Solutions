#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int xrn[maxn];
int xrm[maxn];

int v1[maxn], v2[maxn];

int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> xrn[i];
	for(int i = 1; i <= m; i++)
		cin >> xrm[i];

	int xr1 = 0, xr2 = 0;

	for(int i = 1; i <= n; i++)
		xr1 ^= xrn[i];
	for(int i = 1; i <= m; i++)
		xr2 ^= xrm[i];

	for(int i = 1; i <= n; i++)
	{
		v1[i] = (xr1 ^xrn[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		v2[i] = (xr1 ^ xrm[i]);
	}




	if(xr1 != xr2)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i = 1; i <= m; i++)
	{
		if(i == 1)
		{
			cout << (xrn[i] ^ v2[i]) << " ";
		}
		else cout << xrm[i] << " \n"[i == m];
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(j == 1)
			{
				cout << xrn[i] << " ";
			}
			else cout << 0 << " \n"[j == m];
		}
	}


}
