#include <iostream>
using namespace std;

int main(){
	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		string x;
		cin >> x;
		int t = x.size();

		if(t > 10){
			cout << x[0] << t-2 << x[t-1] << "\n";
		}else{
			cout << x << "\n";
		}
	}


}
