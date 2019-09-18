#include <bits/stdc++.h>
using namespace std;

int n;

struct point
{
	int x, y;

	bool operator <(const point &p) const
	{
		return x < p.x || (x == p.x && y < p.y);
	}
};

vector<point> pt;

int cross(point o, point a, point b)
{
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}

vector<point> CH()
{
	int sz = pt.size(), k = 0;
	vector<point> H(2*sz);

	sort(pt.begin(), pt.end());

	for(int i = 0; i < sz; i++)
	{
		while(k >= 2 && cross(H[k - 2], H[k - 1], pt[i]) <= 0) k--;
		H[k++] = pt[i];
	}
	for(int i = sz - 2, t = k + 1; i >= 0; i--)
	{
		while(k >= t && cross(H[k - 2], H[k - 1], pt[i]) <= 0) k--;
		H[k++] = pt[i];
	}
	H.resize(k - 1);
	return H;
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		point p;
		p.x = a;
		p.y = b;
		pt.push_back(p);
	}
	vector<point> ans = CH();
	if(ans.size() <= 2)
	{
		cout << 0 << "\n";
	}
	else
	{
		point p = ans[0];
		double area = 0;
		for(int i = 2; i < (int)ans.size(); i++)
		{
			area += (cross(p, ans[i], ans[i - 1]))/2;
		}
		cout << (int)abs(area/50) << "\n";
	}
}
