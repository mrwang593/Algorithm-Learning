#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>dp(m+1,0);
	dp[0]=1;

	for(int j=1;j<=n;j++){
		for(int k=m;k>=1;k--){
			if(k-a[j]>=0)
				dp[k]=(dp[k]+dp[k-a[j]])%10;
		}
	} 
	for(int i=1;i<=n;i++){
		vector<int>g;
		g=dp;
		for(int j=1;j<=m;j++){
			if(j>=a[i])g[j]=(g[j]-g[j-a[i]]+10)%10;
			cout<<g[j]; 
		}
		cout<<endl;
	}
	
	return 0;
} 
