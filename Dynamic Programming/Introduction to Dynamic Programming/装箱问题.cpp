#include<bits/stdc++.h>
using namespace std;
int main(){
	int v,n;
	cin>>v>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>dp(v+1,0);//表示体积为i时最多能装多少体积的货物

	for(int i=1;i<=n;i++){
		for(int j=v;j>=a[i];j--){
			dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		}
	}
	cout<<v-dp[v];
	return 0;
}