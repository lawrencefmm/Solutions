#include <bits/stdc++.h>
using namespace std;

#define int int_fast32_t
#define gc getchar_unlocked
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


const int MAXN = 5e6 + 10, MAXM = 110;

int n, v[MAXM], qt[MAXM], qtb[MAXM], sz;
bool dp[MAXN];

int c[MAXN];

inline int scan(){
	int n=0, x=gc(), s=1;
	for(;x<'0'||x>'9';x=gc()) if(x=='-') s=-1;
	for(;x>='0'&&x<='9';x=gc()) n = 10*n + x - '0';
	return n*s;
}

inline void build()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= 8; j++)
		{
			int aux = 1 << j;
			if((1 << j) <= qt[i])
			{
				qt[i] -= aux;
				c[++sz] = (aux*v[i]);
			}
		}
		if(qt[i] > 0) c[++sz] = (qt[i]*v[i]);
	}
}

int32_t main()
{

	ios::sync_with_stdio(false);

	n = scan();

	for(int i = 0; i < n; i++)
	{
		qt[i] = qtb[i] = scan();
		v[i] = scan();

		v[n] += qt[i]*v[i];
	}

	build();

	dp[0] = 1;

	for (int j = 1; j <= sz; j++)
		for (int i = (v[n]/2) - c[j]; i >= 0; i--)
			dp[i+c[j]] |= dp[i];

	int res = MAXN*2;

	for (int i = 0; i <= v[n]/2; i++)
		if (dp[i])
			res = min(res, abs(2*i-v[n]));

	cout << res << "\n";
}
