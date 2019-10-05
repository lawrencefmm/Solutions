#include <bits/stdc++.h>
#include "inaho.h"
using namespace std;

const int MAXN = 5e5 + 10;

int pai[MAXN], w[MAXN];

struct ch
{
	int v, pai;
	int u, w;
};

ch create(int v, int pai, int u, int w)
{
	ch aux;
	aux.v = v;
	aux.pai = pai;
	aux.u = u;
	aux.w = w;
	return aux;
}

stack<ch> ver;

int find(int x)
{
	if(pai[x] == x) return x;
	return find(pai[x]);
}

void join(int a, int b)
{
	a = find(a);
	b = find(b);

	if(a == b)
	{
		ver.push(create(0, 0, 0, 0));
		return;
	}

	if(w[a] > w[b])
	{
		ver.push(create(b, pai[b], a, w[a]));
		pai[b] = a;
		w[a] += w[b];
	}
	else
	{
		ver.push(create(a, pai[a], b, w[b]));
		pai[a] = b;
		w[b] += w[a];
	}
}

void Init(int N)
{
	for(int i = 1; i < MAXN; i++) pai[i] = i, w[i] = 1;
}

void AddEdge(int U, int V)
{
	join(U, V);
}

void RemoveLastEdge()
{
	ch aux = ver.top();
	pai[aux.v] = aux.pai;
	w[aux.u] = aux.w;
	ver.pop();
}

int GetSize(int U)
{
	U = find(U);
	return w[U];
}
