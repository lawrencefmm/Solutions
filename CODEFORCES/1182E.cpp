#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ll;

template <int n, int m>
struct Matrix
{
	ll v[n][m];

	static Matrix<n, m> ones()
	{
		Matrix<n, m> ans{};
		for (int i = 0; i < n; i++)
			ans.v[i][i] = 1;
		return ans;
	}
};

ll mod = 1e9+7;

template <int n, int m, int p>
Matrix<n, p> operator*(Matrix<n, m> const& a, Matrix<m, p> const& b)
{
	auto ans = Matrix<n, p>{};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			for (int k = 0; k < m; k++)
				ans.v[i][j] = (ans.v[i][j] + a.v[i][k]%mod * b.v[k][j]) % mod;
	return ans;
}

template <int n>
Matrix<n, n> power(Matrix<n, n> a, ll b)
{
	auto ans = Matrix<n, n>::ones();
	while (b)
	{
		if (b&1ll) ans = ans*a;
		a = a*a;
		b >>= 1;
	}
	return ans;
}

ll int_power(ll a, ll b)
{
	//cout << a << " " << b << "\n";
	ll ans = 1ll;

	while (b)
	{
		if (b&1ll) ans = (ans*a)%mod;
		a = (a*a)%mod;
		b /= 2ll;
	}
	return ans;
}

int32_t main()
{
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	Matrix<3, 1> f1_base = {1, 0, 0};
	Matrix<3, 1> f2_base = {0, 1, 0};
	Matrix<3, 1> f3_base = {0, 0, 1};
	Matrix<3, 1> G_base = {1, 2, 3};

	Matrix<3,3> exp = {0, 1, 0,
	                   0, 0, 1,
	                   1, 1, 1};

	mod--;
	auto f1_expo = power(exp, n - 1) * f1_base;
	auto f2_expo = power(exp, n - 1) * f2_base;
	auto f3_expo = power(exp, n - 1) * f3_base;
	auto G_expo = power(exp, n - 1) * G_base;

	ll f1, f2, f3, Cn;
	ll Gn = ((G_expo.v[0][0] - n%mod + mod)%mod + mod)%mod;
	//cout << G_expo.v[0][0] << " " << Gn <<"\n";

//	cout << "oi " << (-7+mod)%mod << endl;
	mod++;
	f1 = int_power(a, f1_expo.v[0][0]);
	f2 = int_power(b, f2_expo.v[0][0]);
	f3 = int_power(c, f3_expo.v[0][0]);
	Cn = int_power(d, Gn);

	//cout << f1 << " " << f2 << " " << f3 << " " << Cn << "\n";

	ll ans = (((f1%mod * f2%mod) % mod) * ((f3 % mod * Cn%mod) % mod)) % mod ;

	cout << ans << "\n";
}
