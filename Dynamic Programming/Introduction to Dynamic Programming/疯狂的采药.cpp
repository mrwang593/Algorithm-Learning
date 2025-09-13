//完全背包
#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,m;
	cin>>T>>m;
	vector<int>t(m+1),w(m+1);
	for(int i=1;i<=m;i++) cin>>t[i]>>w[i];
	vector<long long>dp(T+1,0);
	for(int i=1;i<=m;i++){
		for(int j=t[i];j<=T;j++){
			dp[j]=max(dp[j],dp[j-t[i]]+w[i]);
		}
	}
	cout<<dp[T];
	return 0;
}