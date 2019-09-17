#include <bits/stdc++.h>
using namespace std;

typedef int_fast64_t ll;
const ll mod = 998244353;
const int alpha = 63;


ll n, D[alpha][alpha][alpha][12], wr[alpha][alpha][12], ans;
vector<int> pos;

int get(char c)
{
	if ('a' <= c && c <= 'z') return c - 'a';
	if ('A' <= c && c <= 'Z') return 26 + (c - 'A');
	return 52 + (c - '0');
}

ll coef[2][2][2]={{{24,12}, {12,4}}, {{12,6}, {4,1}}};

void readInput()
{
	set<string> temp;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string st, rt;
		cin >> st;
		rt = st;
		reverse(rt.begin(), rt.end());

		temp.insert(st);
		temp.insert(rt);
	}

	for(auto u : temp)
	{
		int sz = u.size();
		wr[get(u[0])][get(u[sz - 1])][sz]++;
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	readInput();


    for(int a = 0; a < alpha; a++)
	{
		for(int b = a; b < alpha; b++)
		{
			for(int c = b; c < alpha; c++)
			{
				for(int d = 0; d < alpha; d++)
				{
					for(int sz = 3; sz <= 10; sz++)
					{
                        //cout << a << " " << b << " " << c << " " << d << "\n";
						D[a][b][c][sz] = (D[a][b][c][sz] + wr[d][a][sz] %mod* wr[d][b][sz]%mod * wr[d][c][sz]%mod) % mod;
					}
				}
			}
		}
	}

    for(int a = 0; a < alpha; a++)
	{
		for(int b = a; b < alpha; b++)
		{
			for(int c = b; c < alpha; c++)
			{
				for(int d = c; d < alpha; d++)
				{
					for(int sz = 3; sz <= 10; sz++)
					{
						ans = (ans + coef[a == b][b == c][c == d]*D[a][b][c][sz]%mod*D[a][b][d][sz]%mod*D[a][c][d][sz]%mod*D[b][c][d][sz]%mod)%mod;
					}
				}
			}
        }
	}


	cout << ans << "\n";
}
