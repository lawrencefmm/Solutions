#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;


	int maiorx = 0, maiory = 0, menorx = 1e9, menory = 1e9;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int a, b;

		cin >> a >> b;

		maiorx = max(maiorx, a);
		menorx = min(menorx, a);
		maiory = max(maiory, b);
		menory = min(menory, b);
	}

	int l = max(maiorx - menorx, maiory - menory);

	cout << l*l << "\n";
}
