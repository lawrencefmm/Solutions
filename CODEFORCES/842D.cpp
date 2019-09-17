#include <bits/stdc++.h>
using namespace std;


struct node
{
	int sz[2];
	node* v[2];

	node()
	{
		sz[0] = sz[1] = 0;
		v[0] = v[1] = nullptr;
	}
};


void insert(node* trie, int x)
{
	for(int i = 20; i >= 0; i--)
	{
		int bit = ((x & (1 << i)) > 0);

		if(trie -> v[bit] == nullptr) trie -> v[bit] = new node();

		trie -> sz[bit]++;
		trie = trie -> v[bit];
	}
}


int find(node *trie, int x)
{
	node *t = trie;
	int ans = 0;

	for (int i = 20; i >= 0; i--)
	{
		int bit = ((x & (1 << i)) > 0);

		if(bit == 0)
		{
			if(t -> v[0] == nullptr) return ans;
			else if(t -> sz[0] != (1 << i)) t = t -> v[0];
			else
			{
				ans += (1 << i);
				if(!t -> sz[1]) return ans;
				else t = t -> v[1];
			}
		}
		else
		{
			if(t -> v[1] == nullptr) return ans;
			else if(t -> sz[1] != (1 << i)) t = t -> v[1];
			else
			{
				ans += (1 << i);
				if(!t -> sz[0]) return ans;
				else t = t -> v[0];
			}
		}

	}

	return ans;
}

bool mark[301010];

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	node* trie = new node();

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(!mark[a]) insert(trie, a);
		mark[a] = true;
	}

	int x = 0;

	while(m--)
	{
		int val;
		cin >> val;

		x ^= val;

		cout << find(trie, x) << "\n";
	}
}
