#include <bits/stdc++.h>
using namespace std;


int num[10] = {1, 2, 3, 4, 5, 6, 7, 8,9, 11};

bool zero(int x)
{
	while(x)
	{
		if(x % 10 == 0)
		{
			return true;
		}
		x /= 10;
	}

	return false;
}


int main()
{
	int n;
	cin >> n;


	n++;
	while((zero(n)))
	{
		n += 1;
	}
	cout << n;
}
