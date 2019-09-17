#include <bits/stdc++.h>
using namespace std;

char ch[4] = {'A', 'B', 'X', 'Y'};

string guess_sequence(int N)
{
	string s;
	string s1 = "AB";
	string s2 = "A";
	string s3 = "X";

	if(press(s1))
	{
		if(press(s2)) s += 'A';
		else s += 'B';
	}
	else
	{
		if(press(s3)) s += 'X';
		else s += 'Y';
	}

	if(N == 1) return s;

	char ft = s[0];

	vector<string> p;

	if('A' == ft)
	{
		p.push_back("B");
		p.push_back("XB");
		p.push_back("XX");
		p.push_back("XY");
	}
	else if('B' == ft)
	{
		p.push_back("A");
		p.push_back("XA");
		p.push_back("XX");
		p.push_back("XY");
	}
	else if('X' == ft)
	{
		p.push_back("A");
		p.push_back("BA");
		p.push_back("BB");
		p.push_back("BY");
	}
	else
	{
		p.push_back("A");
		p.push_back("BA");
		p.push_back("BB");
		p.push_back("BX");
	}

	while((int)s.size() < N - 1)
	{
		int t = press(s + p[0] + s + p[1] + s + p[2] + s + p[3]);
		if(t == s.size() + 1) s += p[0];
		else if(t == s.size() + 2) s += p[2][0];
		else s += p[3][1];
	}

	for(int i = 0, t = 0; i < 4; i++, t++)
	{
		if(ch[i] == ft)
		{
			t--;
			continue;
		}
		if(t == 2)
		{
			s += ch[i];
			break;
		}
		if(press(s + ch[i]) > s.size())
		{
			s += ch[i];
			break;
		}

	}
	return s;
}
