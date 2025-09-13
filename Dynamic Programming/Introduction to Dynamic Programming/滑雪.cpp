#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	cin>>n>>x;
	vector<long long>lose(n+1),win(n+1),use(n+1);
	for(int i=1;i<=n;i++) cin>>lose[i]>>win[i]>>use[i];
	vector<long long>dp(x+1,0);
	for(int i=1;i<=n;i++){
		for(int j=x;j>=0;j--){
			if(j>=use[i])dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
			else dp[j]=dp[j]+lose[i];
		}
	}
	cout<<1ll*dp[x]*5;
	return 0;
}