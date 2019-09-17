#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
#define int int_fast64_t

#pragma GCC optimize("Ofast")

int pref[maxn], v[maxn];

inline int find_min_cost(int i, int j)
{
	int ct = 0;
	int media = (int)(j + i)/2;

	ct = v[media]*(2*media - i - j) + pref[j] - pref[media];

	if(i != 0) ct += pref[i - 1];

	if(media != 0) ct -= pref[media - 1];

	return ct;
}

int32_t besthub(int32_t R, int32_t L, int32_t X[], long long B)
{
	for(int i = 0; i < R; i++)
	{
		if(i) pref[i] = pref[i - 1] + X[i];
		else pref[i] = X[i];
		v[i] = X[i];
	}

	int best = 0;

	int l = 0, r = 0;

	while(l <= r)
	{
		best = max(best, r - l + 1);

		if(r + 1 < R)
		{
			if(find_min_cost(l, r + 1) <= B) r++;

			if(find_min_cost(l, r + 1) > B)
			{
				r++;

				while(find_min_cost(++l, r) > B);
			}
		}
		else break;
	}

	return best;
}
