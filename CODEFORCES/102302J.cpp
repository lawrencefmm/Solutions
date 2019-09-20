#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll mul(ll a, ll b, ll c)
{
	return (a%c*b%c)%c;
}

inline ll power(ll a, ll b, ll c)
{
	ll res = 1;
	while(b) {

		if (b&1) res = mul(res, a, c);
		a = mul(a, a, c);
		b >>= 1;
	}
	return res;
}

inline bool witness(ll a, ll d, ll s, ll n)
{
	ll x = power(a, d, n), y;

	while (s--) {
`
		y = mul(x, x, n);

		if (y == 1 and x != 1 and x != n-1) return false;

		x = y;
	}

	if (y != 1) return false;
	return true;
}

ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

inline bool is_prime(ll n)
{
	if (n < 2) return false;
	if (n == 2 or n == 3) return true;
	if (n%2 == 0 or n%3 == 0) return false;

	ll s = __builtin_ctzll(n-1), d = (n-1)>>s;

	for (ll p : primes) {

		if (n == p) return true;
		if (!witness(p, d, s, n)) return false;
	}

	return true;
}

int main()
{
	ll n;
	ll v[100010];

	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n;
	ll meio = 0;

	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	sort(v + 1, v + 1 + n);

	meio = v[n/2 + 1];

	//cout << meio << "\n";

	sort(v + 1, v + n + 1);

	ll ans = 1e18;

	for(ll i = 0; i <= 1000ll; i++)
	{
		ll ans1 = 0, ans2 = 0;
		if(meio - i < 2 and meio + i > 10000000000ll) break;

		bool case1 = is_prime(meio + i);
		bool case2 = is_prime(meio - i);

		//cout << meio + i << " " << meio - i << "\n";
		if(case1)
		{
			for(ll j = 1; j <= n; j++)
			{
				ans1 += abs(meio + (ll)i - v[j]);
			}
		}
		if(case2)
		{
			for(ll j = 1; j <= n; j++)
			{
				ans2 += abs(meio - (ll)i - v[j]);
			}
		}

		if(case1) ans = min(ans, ans1);
		if(case2) ans = min(ans, ans2);
	}

	cout << ans << "\n";


}
