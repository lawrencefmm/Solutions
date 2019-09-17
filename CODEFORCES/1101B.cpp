#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	string v;
	cin >> v;

	int x = -1, y = -1, z = -1, w = -1;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == '[' and x == -1) x = i;
		if(v[i] == ']') w = i;
	}

	for(int i = x + 1; i < w; i++)
	{
		if(v[i] == ':' and y == -1) y = i;
		if(v[i] == ':') z = i;
	}
	if(y == z or x == -1 or y == -1 or z == -1 or w == -1)
	{
		cout << -1 << "\n";
		//cout << x << " " << y << " " << z << " " <<
		return 0;
	}

	int cont = 0;

	for(int i = y + 1; i < z; i++)
	{
		if(v[i] != '|') cont++;
	}

	//cout << x << " " << y << " " << z << " " << w << "\n";

	cout << (v.size() - cont - x - (w - z - 1)) - (y - x - 1) - (v.size() - w - 1) << "\n";
	//cout << v.size() << " " << cont << "\n";

}
