#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>color(n+1);
	vector<int>p(m+1);
	for(int i=1;i<=n;i++) cin>>color[i];
	for(int i=1;i<=m;i++) cin>>p[i];
	vector<long long>dp(n+1);
	vector<unordered_map<int,int>>dpc(n+1);
	dp[1]=p[color[1]];
	dpc[1][color[1]]=1;
	if(color[2]==color[1]){
		dp[2]=dp[1];
		dpc[2]=dpc[1];
	} 
	else{
		dp[2]=dp[1]+p[color[2]];
		dpc[2][color[1]]=dpc[2][color[2]]=1;
	}
	for(int i=3;i<=n;i++){
		long long p1=LLONG_MAX,p2=LLONG_MAX;
		
		if(dpc[i-1][color[i]]==1) p1=dp[i-1];
		else p1=dp[i-1]+p[color[i]];
		
		if(dpc[i-2][color[i]]==1) p2=dp[i-2];
		else p2=dp[i-2]+p[color[i]];
	
		if(p1<p2){
			dp[i]=p1;
			dpc[i]=dpc[i-1];
			dpc[i][color[i]]=1;	
		}
		else{
			dp[i]=p2;
			dpc[i]=dpc[i-2];
			dpc[i][color[i]]=1;
		}
	}
	cout<<dp[n];
	return 0; 
} 
