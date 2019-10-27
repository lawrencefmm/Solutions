#include <bits/stdc++.h>
using namespace std;

double v[200010];
int n;

double calc(double x)
{
    double best = 0.0;
    double at = 0.0;
    for(int i = 0; i < n; i++)
    {
        at = max(0.0, at + v[i] - x);
        best = max(best, at);
    }

	at = 0.0;

	for(int i = 0; i < n; i++)
    {
        at = min(0.0, at + v[i] - x);
        best = max(best, abs(at));
    }

    return best;
}

double search()
{
    double l = -1e5, r = 1e5;

    for(int i = 0; i < 300; i++)
    {
        double cl = l + (r - l)/3.0;
        double cr = r - (r - l)/3.0;

        if(calc(cl) < calc(cr)) r = cr;
        
        else l = cl;
    }

	return calc(l);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	cout << fixed << setprecision(9) << search() << endl;
}