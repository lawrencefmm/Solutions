#include <bits/stdc++.h>
using namespace std;


#define int long long

int32_t main()
{
	int n, q;
	cin >> n >> q;

	deque<int> v;
	int maxi = 0;

	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		maxi = max(maxi, a);
	}

	vector<pair<int,int>> pre_ans;

	while(true)
	{
		int a = v[0], b = v[1];
		v.pop_front();
		v.pop_front();

		v.push_back(min(a, b));
		v.push_front(max(a, b));
		pre_ans.push_back({a, b});

		if(a == maxi or b == maxi) break;
	}

	v.pop_front();

	// cout << pre_ans.size() << "\n";

	// for(auto u : v) cout << u << " ";

	// cout << "\n";

	while(q--)
	{
		long long query;
		cin >> query;

		if(query <= (long long)pre_ans.size())
		{
			cout << pre_ans[query - 1].first << " " << pre_ans[query-1].second << "\n";
		}
		else
		{
			cout << maxi << " ";

			long long pos = (query - (long long)pre_ans.size() - 1)%(n - 1);
			cout << v[pos] << "\n";
			//cout << pos << " \n";
		}
	}

}
