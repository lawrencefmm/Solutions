#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main()
{
	cin >> n >> k;
	cin >> s;
	sort(s.begin(), s.end());

	int ans = 0;
	int cont = 0;
	int temp;
	for(int i = 0; i < (int)s.size(); i++)
	{
		if(cont == k) break;
		if(i == 0){
			ans += s[i] - 'a' + 1;
			temp = s[i];
			cont++;
			continue;
		}
		if(s[i] -  temp > 1)
		{
			ans += s[i] - 'a' + 1;
			temp = s[i];
			cont++;
		}
	}

	if(cont < k)
	{
		cout << -1 << "\n";
		return 0;
	}
	cout << ans << "\n";
}
