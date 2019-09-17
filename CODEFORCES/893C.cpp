#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int maxn=1e5+10;
int N,M,mark[maxn];
pair<int,int> custo[maxn];
vector<int> G[maxn];
int DFS(int x){
	mark[x]=1;
	for(int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if(mark[v]==-1){
			DFS(v);
		}
	}
}
 main(){
 	ios::sync_with_stdio(false),cin.tie(0);
	memset(mark,-1,sizeof(mark));
	cin >> N >> M;
	int r=0;
	for(int i=1;i<=N;i++){
		int a;
		cin >> a;
		custo[i]=make_pair(a,i);
	}
	for(int i=1;i<=M;i++){
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	sort(custo+1,custo+N+1);
	for(int i=1;i<=N;i++){
		if(mark[custo[i].second]==-1){
			r+=custo[i].first;
			DFS(custo[i].second);
		}
	}
	cout << r << endl;
}
