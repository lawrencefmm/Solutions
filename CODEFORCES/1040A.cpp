#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n, a, b;
	cin >> n >> a >> b;
	int vet[30];
	for(int i = 0; i < n; i++)
	{
		cin >> vet[i];
	}

	int ans = 0;
	int mid = n/2 + (n&1 == 1);
	for(int i = 0; i < mid; i++)
	{
		if(i == mid - 1 and mid == n/2  + 1)
		{
			if(vet[i] == 2)	ans += min(a, b);
			break;
		}
		if(vet[i] == 2)
		{
			if(vet[n - i - 1] == 2)
			{
				ans += 2*min(a, b);
			}
			else
			{
				if(vet[n - i - 1] == 1)
					ans += b;
				else ans += a;
			}
		}
		else if(vet[n - i - 1] == 2)
		{
			if(vet[i] == 1)
				ans += b;
			else ans += a;
		}
		if(vet[i] != vet[n - i - 1] and vet[i] != 2 and vet[n - i - 1] != 2)
		{
			cout << "-1\n";
			//cout << i << " " << n - i - 1;
			return 0;
		}
	}
	cout << ans << "\n";

}
