#include <bits/stdc++.h>
using namespace std;


int ans[101010];

struct node
{
	int qt = 0;
	node *v[30];

	node()
	{
		for(int i = 0; i < 30; i++) v[i] = nullptr;
	};
};

void insert(node* at, const string& s)
{
	for(int i = 0; i < s.size(); i++)
	{
		char u = s[i];

		if(at -> v[u - 'a'] == nullptr) at -> v[u - 'a'] = new node();

		ans[i + 1] = max(ans[i  + 1], ++(at ->  v[u - 'a']) -> qt);
		at = at -> v[u -'a'];
	}
}

void clear(node*& trie)
{
	for(int i = 0; i < 30; i++)
	{
		if(trie -> v[i] == nullptr) continue;
		clear(trie -> v[i]);
	}
	delete trie;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int t;
	cin >> t;

	while(t--)
	{
		memset(ans, 0, sizeof(ans));
		node* trie = new node();
		int n, q;

		cin >> n >> q;

		for(int i = 0; i < n; i++)
		{
			string a;
			cin >> a;

			reverse(a.begin(), a.end());

			insert(trie, a);
		}

		while(q--)
		{
			int x;
			cin >> x;
			cout << ans[x] << "\n";
		}

		clear(trie);
	}
}
