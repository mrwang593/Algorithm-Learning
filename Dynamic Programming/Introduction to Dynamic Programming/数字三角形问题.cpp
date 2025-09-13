#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int>>a(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	vector<vector<int>>dp(n+2,vector<int>(n+2,0));
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			dp[i][j]=max(a[i][j]+dp[i+1][j],a[i][j]+dp[i+1][j+1]);
		}
	}
	cout<<dp[1][1];
	return 0;
}