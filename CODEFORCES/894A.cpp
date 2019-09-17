#include <bits/stdc++.h>
using namespace std;

int main(){
	long long cont=0;
	string x;
	cin >> x;
	for(int i=0;i<(int)x.size();i++){
		if(x[i]=='Q'){
			for(int k=i+1;k<(int)x.size();k++){
				if(x[k]=='A'){
					for(int j=k+1;j<(int)x.size();j++){
						if(x[j]=='Q'){
							cont ++;
						}
					}
				}
			}
		}
	}
	cout << cont;


}
