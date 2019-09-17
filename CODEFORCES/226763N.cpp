#include <bits/stdc++.h>
using namespace std;

int cont;
string s;

bool is_palindrome(int x, int y)
{
	bool ok = true;
	cont = 0;
	while(x <= y)
	{
		if(s[x] != s[y])
		{
			return false;
		}
		x++;
		y--;
		cont += 2;
		if(x == y) cont--;
	}
	return true;
}


int main()
{
	cin >> s;


	bool ok = true;
	for(int i = 0; i < (int)s.size(); i++)
	{
		for(int j = i + 1; j < (int)s.size(); j++){
			if(is_palindrome(i, j) and !(cont % 2))
			{
				ok = false;
			}
		}
	}
	if(ok)
	{
		cout << "Odd.\n";
		return 0;
	}
	cout << "Or not.\n";
	return 0;

}
