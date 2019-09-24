#include <bits/stdc++.h>
using namespace std;


string a, b;

map<int, string> dp[110];

string solve(int l, int r)
{
	if(l == a.size() and r == b.size()) return "";
	else if(dp[l].find(r) != dp[l].end()) return dp[l][r];
	else if(l == a.size()) return dp[l][r] = b[r] + solve(l, r + 1);
	else if(r == b.size()) return dp[l][r] = a[l] + solve(l + 1, r);
	else if(a[l] == b[r]) return dp[l][r] = a[l] + solve(l + 1, r + 1);
	else
	{
		string caso1 = a[l] + solve(l + 1, r);
		string caso2 = b[r] + solve(l, r + 1);
		if(caso1.size() <  caso2.size()) return dp[l][r] = caso1;
		else return dp[l][r] = caso2;
	}
}

int main()
{
	int cont = 0;

	while(cin >> a)
	{
		if(a == "#") break;
		for(int i = 0; i < 110; i++) dp[i].clear();

		cin >> b;

		string ans = solve(0, 0);

		cout << "Teste " << ++cont << "\n";
		cout << ans << "\n\n";
	}

}