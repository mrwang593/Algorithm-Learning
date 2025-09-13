#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,w;
	cin>>n>>w;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int>dp(w+1,-1);
	dp[0]=0;
	for(int i=1;i<=w;i++){
		int minm=INT_MAX;
		for(int j=0;j<n;j++){
			if(i-a[j]>=0&&dp[i-a[j]]!=-1) minm=min(minm,dp[i-a[j]]+1);
		}
		if(minm!=INT_MAX)dp[i]=minm;//只有在找到正确的组合后才能更新
	}
	cout<<dp[w];
	return 0;
}