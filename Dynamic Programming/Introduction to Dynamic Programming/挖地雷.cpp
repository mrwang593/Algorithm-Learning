#include<bits/stdc++.h>
using namespace std;
vector<int>cnt;
vector<vector<int>>a;
vector<int>inDegree,dp,nxt;
int dfs(int u){
	if(dp[u]!=-1) return dp[u];
	if(a[u].empty()) return dp[u]=cnt[u];

	for(int v:a[u]){
		if(dfs(v)+cnt[u]>dp[u]){
			nxt[u]=v;
			dp[u]=dfs(v)+cnt[u];
		}
	}
	return dp[u];
}
int main(){
	int n;
	cin>>n;
	cnt.resize(n+1);
	for(int i=1;i<=n;i++) cin>>cnt[i];
	a.resize(n+1);
	inDegree.resize(n+1,0);
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			int x; cin>>x;
			if(x) a[i].push_back(j),inDegree[j]++;
		}
	}
	dp.resize(n+1,-1);
	nxt.resize(n+1,-1);
	int maxm=INT_MIN,start=-1;
	for(int i=1;i<=n;i++){
		if(inDegree[i]==0){
			int val=dfs(i);
			if(val>maxm){
				maxm=val;
				start=i;
			}
		}
	}
	while(start!=-1){
		cout<<start<<" ";
		start=nxt[start];
	}
	cout<<"\n";
	cout<<maxm;
	return 0;
}