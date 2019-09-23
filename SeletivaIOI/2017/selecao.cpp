#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main()
{
	int n, k;
	int ax, bx, cx, mx;
	int ay, by, cy, my;


	cin >> n >> k;
	cin >> ax >> bx >> cx >> mx;
	cin >> ay >> by >> cy >> my;

	int X[n + 10];
	int Y[n + 10];
	X[1] = ax;
	Y[1] = ay;

	for(int i = 2; i <= n; i++)
	{
		X[i] = (bx + cx*X[i-1])%mx;
		Y[i] = (by + cy*Y[i-1])%my;
		//cout << X[i] << " " << Y[i] << "\n";
	}

	vector<int> v;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			v.push_back((X[i] + Y[j]));
		}
	}
	//for(int u : v) cout << u << " ";
	//cout << "\n";
	sort(v.begin(), v.end());
	// cout << v.size() << "\n";
	cout << v[k - 1] << "\n";
}