#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int unsigned long long

const int mod = 1e9 + 7;

template<int n, int m>
struct mat
{
	int v[n][m];

	static mat<n, m> id()
	{
		mat<n, m> ans{};
		for(int i = 0; i < n; i++)
		{
			ans.v[i][i] = 1;
		}
		return ans;
	}
};

template<int n, int m, int p>
mat<n, p> operator*(const mat<n, m>& a, const mat<m, p>& b)
{
	auto ans = mat<n, p>{};

	for(int i = 0; i < n; i++)
		for(int j = 0; j < p; j++)
			for(int k = 0; k < m; k++)
				ans.v[i][j] = (ans.v[i][j] + ((a.v[i][k])%mod)*((b.v[k][j]))%mod) % mod;

	return ans;
}

template <int n>
mat<n, n> power(mat<n, n> a, int b)
{
	auto ans = mat<n, n>::id();
	while (b)
    {
		if (b&1) ans = ans*a;
		a = a*a;
		b /= 2;
	}
	return ans;
}

int32_t main()
{
	int n;
	cin >> n;

	mat<2, 1> bs = {0, 1};
	mat<2,2> exp = {1, 1, 1, 0};

	auto ans = power(exp, n)*bs;
	cout << ans.v[0][0]%mod << "\n";
}
