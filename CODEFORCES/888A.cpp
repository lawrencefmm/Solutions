#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, cont=0;
	int a[1010];
	cin >> n;
	for(int i=1 ; i<=n;i++){
		cin >> a[i];

	}

	for(int i=2;i<n;i++){
		if(a[i]>a[i-1] and a[i]>a[i+1]){
			cont++;
		}else if(a[i]<a[i-1] and a[i]<a[i+1]){
			cont ++;
		}
	}
    cout << cont;
}
