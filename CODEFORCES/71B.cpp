#include<bits/stdc++.h>
using namespace std;

int n, k, t, a, cont;
int vec[110];

int main(){

	cin >> n >> k >> t;
	a = n*k*t/100;

	while(a > 0){
		if(a >= k){
			vec[cont]+=k;
			a-=k;
			cont++;
			continue;
		}
		if(a <= k){
			vec[cont] += a;
			a = 0;
			break;
		}

	}
	for(int i = 0; i < n; i++){
		cout << vec[i] << " ";
	}
}
