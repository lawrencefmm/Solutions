#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<int, string> mp;
	vector<string> bt;
	vector<pair<string, int>> bug;

	bt.push_back("");
	bt.push_back("abc");
	bt.push_back("def");
	bt.push_back("ghi");
	bt.push_back("jkl");
	bt.push_back("mno");
	bt.push_back("pqrs");
	bt.push_back("tuv");
	bt.push_back("wxyz");



	for(int i = 1; i <= 9; i++)
	{
		int a;
		cin >> a;
		bug.push_back({bt[a - 1], i});
	}

	string word;
	cin >> word;


	string seq;
	for(auto c : word)
	{
		string num;

		for(auto u : bug)
		{
			for(int i = 0; i < u.first.size(); i++)
			{
				if(u.first[i]  == c)
				{
					if((int)seq.size())
					{
						// cout << seq << "\n";
						// cout << i << "\n";
						if(seq[seq.size() - 1] == u.second + '0')
						{
							seq += "#";
						}
					}
					for(int t = 0; t < i + 1; t++)
						num += (u.second +'0');
				}
			}
		}
		seq += num;
	}

	cout << seq << "\n";


}
