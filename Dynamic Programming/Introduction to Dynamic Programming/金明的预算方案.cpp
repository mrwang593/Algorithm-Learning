#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>g(m+1,vector<int>(2,0)),w(m+1,vector<int>(2,0));
	for(int i=1;i<=m;i++){
		int v,p,q;
		cin>>v>>p>>q;
		if(!q){
			w[i][0]=v*p,g[i][0]=v;
		}
		else {
			if(w[q][1]) w[q][2]=v*p,g[q][2]=v;
			else w[q][1]=v*p,g[q][1]=v;
		}
	}
	vector<int>dp(n+1,0);
	for(int i=1;i<=m;i++){
		for(int j=n;j>=0;j--){
			if(j>=g[i][0]) dp[j]=max(dp[j],dp[j-g[i][0]]+w[i][0]);
			if(j>=g[i][0]+g[i][1]) dp[j]=max(dp[j],dp[j-g[i][0]-g[i][1]]+w[i][0]+w[i][1]);
			if(j>=g[i][0]+g[i][2]) dp[j]=max(dp[j],dp[j-g[i][0]-g[i][2]]+w[i][0]+w[i][2]);
			if(j>=g[i][0]+g[i][1]+g[i][2]) dp[j]=max(dp[j],dp[j-g[i][0]-g[i][1]-g[i][2]]+w[i][0]+w[i][1]+w[i][2]);
		}
	}
	cout<<dp[n];
	return 0;
}
/*
1000 5
300 2 0
400 5 1
300 5 1
400 3 0
500 2 0


*/