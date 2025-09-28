#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>edge;
vector<vector<int>>w; 
int main(){
	int n;
	cin>>n;
	edge.resize(n+1);
	w.resize(n+1);
	int now=1;
	for(int i=1;i<=n;i++){
		char op;
		cin>>op;
		if(op=='?'){
			int u,x;
			cin>>u>>x;
			w[++now]=x;
			edge[now].push_back(u);
			edge[u].push_back(now);
		}
		else{
			int u,v,k;
			cin>>u>>v>>k;
			dfs(u,)
		}
	}
	return 0;
}
