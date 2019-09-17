#include <bits/stdc++.h>
using namespace std;

int main(){
	int t=0;
	int x1,x2,y1,y2,x,y;

	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
	int i=y2-y1;
	int j=x2-x1;

	if(i%y==0 and j%x==0 and (j/x+i/y)%2==0){
		cout<< "YES";

	}else{
		cout << "NO";
	}
	return 0;

}
