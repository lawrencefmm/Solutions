#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = (1ll << 32ll) - 1ll;

int32_t main()
{
	int t;
	cin >> t;

	int x = 0;

	int flag = 0;

	stack<int> fores;
	int total = 1;

	for(int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		if(s[0] == 'a')
		{
			if(flag)
			{
				cout << "OVERFLOW!!!\n";
				return 0;
			}
			if((int)fores.size())
			{
				if(total > maxn)
				{
					cout << "OVERFLOW!!!\n";
					return 0;
				}
				if(x  + total> maxn)
				{
					cout << "OVERFLOW!!!\n";
					return 0;
				}
				x += total;
			}

			else x++;

			if(x > maxn)
			{
				cout << "OVERFLOW!!!\n";
				return 0;
			}
		}
		else if(s[0] == 'f')
		{
			int val;
			cin >> val;
			if(total * val > maxn or flag) flag++;
			else
			{
				total *= val;
				fores.push(val);
			}
		}
		else
		{
			if(flag) flag--;
			else
			{
				total /= fores.top();
				fores.pop();
			}
		}
	}

	cout << x << "\n";
}
