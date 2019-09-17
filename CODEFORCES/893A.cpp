#include <bits/stdc++.h>
using namespace std;

int main(){
	set<int> jogo;
	int n;
	bool ok = true;
	cin >> n;
	jogo.insert(1);
	jogo.insert(2);
	for(int i=1;i<=n;i++){
		int temp;
		cin >> temp;
		if(i==1){
			if(temp==1){
				jogo.erase(2);
				jogo.insert(3);
			}else{
				if(temp==3){
					cout << "NO";
					ok = false;
					break;
				}
				jogo.erase(1);
				jogo.insert(3);
			}
		}else{
			if(temp==1){
				if(jogo.find(1)==jogo.end()){
					cout << "NO";
					ok = false;
					break;
				}else{
					if(jogo.find(2)==jogo.end()){
						jogo.erase(3);
						jogo.insert(2);
					}else{
						jogo.erase(2);
						jogo.insert(3);
					}
				}
			}else if(temp==2){
				if(jogo.find(2)==jogo.end()){
					cout << "NO";
					ok = false;
					break;
				}else{
					if(jogo.find(1)==jogo.end()){
						jogo.erase(3);
						jogo.insert(1);
					}else{
						jogo.erase(1);
						jogo.insert(3);
					}
				}
			}else if(temp==3){
				if(jogo.find(3)==jogo.end()){
					cout << "NO";
					ok = false;
					break;
				}else{
					if(jogo.find(2)==jogo.end()){
						jogo.erase(1);
						jogo.insert(2);
					}else{
						jogo.erase(2);
						jogo.insert(1);
					}
				}
			}

		}
	}
	if(ok){
		cout <<"YES";
	}
}
