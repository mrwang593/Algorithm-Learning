#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	int n,w;
	cin>>n>>w;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>dp(w+1,0);

	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=w;j++){
			//对于每种纸币可以选择用或则不用来构成w元
			dp[j]=(dp[j-a[i]]+dp[j])%mod;
		}
	}
	cout<<dp[w];
	return 0;
}