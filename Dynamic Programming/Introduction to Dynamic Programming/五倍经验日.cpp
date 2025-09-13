#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	cin>>n>>x;
	vector<int>lose(n+1),win(n+1),use(n+1);
	for(int i=1;i<=n;i++) cin>>lose[i]>>win[i]>>use[i];
	vector<int>dp(x+1,0);
	for(int i=1;i<=n;i++){
		for(int j=x;j>=use[i];j--){
			dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
		}
	}
	cout<<dp[x];
	return 0;
}