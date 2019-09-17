#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);


int main()
{
	int n, r;
	cin >> n >> r;
	double seno = sin(pi/n);
	cout << setprecision(9) << (r*(seno))/(1 - seno) << "\n";
}
