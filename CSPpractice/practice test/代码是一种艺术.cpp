#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>nxt;
void dfs(int i,vector<bool>&vis){
	for(int v:nxt[i]){
		if(!vis[v]){
			vis[v]=true;
			dfs(v,vis);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m; 
	nxt.resize(n+1);
	vector<int>inDegree(n+1,0);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		inDegree[v]++;
		nxt[u].push_back(v);
	}
	vector<int>ans;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!inDegree[i]) {
			ans.push_back(i);
			q.push(i);
		}
	}
	vector<bool>vis(n+1,false);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=true;
		for(int v:nxt[u]){
			if(!vis[v]) q.push(v);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			ans.push_back(i);
			dfs(i,vis);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i:ans)cout<<i<<"\n";
	return 0;
} 
