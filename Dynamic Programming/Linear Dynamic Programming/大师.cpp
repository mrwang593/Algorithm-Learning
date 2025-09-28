#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define v 20000
int main(){
	int n;
	cin>>n;
	vector<int>h(n+1);
	for(int i=1;i<=n;i++) cin>>h[i];
	vector<vector<int>>dp(n+1,vector<int>(2*v+10,0));//以i为结尾且公差为j的数列个数
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+1)%mod;
		for(int j=1;j<i;j++){
			dp[i][h[i]-h[j]+v]+=(dp[j][h[i]-h[j]+v]+1)%mod;
			dp[i][h[i]-h[j]+v]%=mod;
			ans=(ans+dp[j][h[i]-h[j]+v]+1)%mod;
		}
	} 
	cout<<ans%mod;
	return 0;
}
