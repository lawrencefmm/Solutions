#include <iostream>
using namespace std;

#define MAX 110
#define INF 100000100

int n, k=1, m[MAX][MAX], resp=-1;

int main(){

  for(int i=0;i<MAX;i++)


  for(int i=1;i<MAX;i++)
    for(int j=1;j<MAX;j++)
      m[i][j]=-INF;

  cin>>n;

  for(int i=1;i<=n;i++){

    for(int j=1;j<=k;j++)
      cin>>m[i][j];

    if(i>0){
      for(int j=1;j<=k;j++){

        m[i][j]=max(m[i-1][j-1]+m[i][j], m[i-1][j]+m[i][j]);
      }
    }

    if(i==n)
        for(int j=1;j<=k;j++)
            if(m[i][j]>resp)
                resp=m[i][j];

    k++;
  }

  cout<<resp<<endl;
}
