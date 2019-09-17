#include <bits/stdc++.h>
using namespace std;

struct node
{
	int qt = 0;
	node *v[2];

	node()
	{
		v[0] = v[1] = nullptr;
	}
};


void insert(node* trie, const string& s, int val)
{
	for(char u : s)
	{
		if(trie -> v[u - '0'] == nullptr)
			trie -> v[u - '0'] = new node();

		trie = trie -> v[u - '0'];
		trie -> qt += val;
	}
}

int find(node* trie, const string& s)
{
	int ans = 0;
	int bit = 30;

	for(char u : s)
	{
		bit--;

		if((trie -> v[1 - (u - '0')]) == nullptr)
		{
			trie = trie -> v[u - '0'];
		}
		else
		{
			if((trie -> v[1 - (u - '0')]) -> qt != 0)
			{
				trie = trie -> v[1 - (u - '0')];
				ans += (1 << bit);
			}
			else
			{
				trie = trie -> v[u - '0'];
			}
		}

	}
	return ans;
}

void clear(node*& trie)
{
	for(int i = 0; i < 2; i++)
	{
		if(trie -> v[i] == nullptr) continue;
		clear(trie -> v[i]);
	}
	delete trie;
}

int main()
{
	int n;
	cin >> n;

	node* trie = new node();

	string zero = "000000000000000000000000000000";

	insert(trie, zero, 1);

	for(int i = 0; i < n; i++)
	{
		char op;
		int x;
		cin >> op >> x;

		string ans;
		while(x)
		{
			ans += (x % 2) + '0';
			x >>= 1;
		}
		while(ans.size() < 30) ans += '0';

		reverse(ans.begin(), ans.end());

		//cout << ans << "\n";

		if(op == '+')
			insert(trie, ans, 1);
		else if(op == '-')
			insert(trie, ans, -1);
		else
			cout << find(trie, ans) << "\n";
	}

	clear(trie);
}
