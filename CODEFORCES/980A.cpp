#include <bits/stdc++.h>
using namespace std;

int main(){
	int cont1 = 0, cont2 = 0;
	string x;
	cin >> x;
	for(int i = 0; i < x.size(); i++){
		if(x[i] == 'o') cont1++;
		else cont2++;

	}
	if(cont1 == 0){
		cout << "YES\n";
	}else if(cont2%cont1 == 0) cout << "YES\n";
	else {
		cout << "NO\n";
	}
}
