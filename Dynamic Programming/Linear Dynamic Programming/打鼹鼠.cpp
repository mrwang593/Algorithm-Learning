#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>t(m+1),x(m+1),y(m+1);
	for(int i=1;i<=m;i++) cin>>t[i]>>x[i]>>y[i];
	int ans=INT_MIN;
	vector<int>dp(m+1,1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<i;j++){
			if(t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j])) dp[i]=max(dp[i],dp[j]+1);//×´Ì¬×ªÒÆ·½³Ì´íÎó 
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
