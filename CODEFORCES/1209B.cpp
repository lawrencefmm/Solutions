#include <bits/stdc++.h>
using namespace std;

int n, a[110], b[110];
string s;


int main()
{
	cin >> n;
	cin >> s;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}

	int best = 0;

	for(int i = 0; i < 100000; i++)
	{
		int cont = 0;
		for(int j = 0; j < n; j++)
		{
			if(i < b[j])
			{
				if(s[j] == '1') cont++;
			}
			else
			{
				int swt = 0;
				swt = (i - b[j])/a[j] + 1;
				if(s[j] == '1')
				{
					if(swt%2 == 0) cont++;
				}
				if(s[j] == '0')
				{
					if(swt%2) cont++;
				}
			}
		}
		best = max(best, cont);
	}

	cout << best << "\n";
}
