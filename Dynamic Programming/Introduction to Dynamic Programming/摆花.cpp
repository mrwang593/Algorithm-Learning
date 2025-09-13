#include<bits/stdc++.h>
using namespace std;
const  int mod=1e6+7;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>cnt(n+1);
	for(int i=1;i<=n;i++) cin>>cnt[i];
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		vector<int>prefix(m+1,0);
		prefix[0]=dp[i-1][0];
		for(int j=1;j<=m;j++) prefix[j]=(prefix[j-1]+dp[i-1][j])%mod;
		for(int j=0;j<=m;j++){
			//数据再大就要用前缀和了
			if(j - cnt[i] - 1 >= 0) {
                dp[i][j] = (prefix[j] - prefix[j - cnt[i] - 1] + mod) % mod;
            } else {
                dp[i][j] = prefix[j];
            }
		}
	}

	cout<<dp[n][m];
	return 0;
}