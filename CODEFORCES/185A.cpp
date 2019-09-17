#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll expo(ll a, ll b, ll mod)
{
    ll ans = 1;

    while(b)
    {
        if(b&1) ans = (ans*(a%mod))%mod;
        a = (a%mod)*(a%mod)%mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
	ll n;
	cin >> n;

	if(n == 0) cout << 1 << "\n";
	else
	{
		ll a, b, c;
		a = 3LL*expo(2LL, n - 1LL, mod), b = expo(2LL, 2LL*n - 1LL, mod), c = expo(2LL, n, mod);

		ll ans = ( ((a%mod + b%mod)%mod - c%mod+mod)%mod )%mod;
		cout << ans << "\n";
	}
}
