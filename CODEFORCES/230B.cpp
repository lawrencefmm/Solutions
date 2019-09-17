#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = (int)1e6 + 10;


int comp[maxn];

void sivo()
{
	comp[1] = 1;
	for(int i = 2; i < maxn; i++)
		if(!comp[i])
			for(int j = i + i; j < maxn; j += i)
				comp[j] = 1;
}

int n;
main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n;
	sivo();
	while(n--)
	{

		int a;
		cin >> a;
		if(a == 1){
			cout << "NO\n";
			continue;
		}
		int x = sqrt(a);
		if(x * x == a and comp[x] == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}
