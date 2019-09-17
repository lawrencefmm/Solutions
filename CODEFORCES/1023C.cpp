#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
#define x first
#define y second

vector<char> stck;
stack<pair<char, int> > st;
bool mark[maxn];

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		stck.push_back(a);
	}
	int cont = 0;
	for(int i = 0; i < n; i++)
	{
		if(cont == n - k) break;
		if(stck[i] == '(') st.push({'(', i});
		if(stck[i] == ')')
		{
			mark[i] = true, mark[st.top().y] = true;
			st.pop();
			cont += 2;
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(mark[i]) continue;
		cout << stck[i];
	}
}
