#include <bits/stdc++.h>
using namespace std;

int main(){
	string x;
	int u=0,d=0,l=0,r=0,n;
	cin >> n;
	cin >> x;
	for(int i=0;i<n;i++){
		if(x[i]=='U'){
			u++;
		}
		if(x[i]=='D'){
			d++;
		}
		if(x[i]=='L'){
			l++;
		}
		if(x[i]=='R'){
			r++;
		}

	}
	cout << 2*min(u,d)+2*min(l,r);


}
