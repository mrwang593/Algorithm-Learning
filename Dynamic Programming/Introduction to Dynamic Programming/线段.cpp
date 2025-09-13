#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>l(n+1),r(n+1);
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
	vector<vector<int>>dp(n+1,vector<int>(2));
	dp[1][0]=r[1]-1+r[1]-l[1];
	dp[1][1]=r[1]-1;
	for(int i=2;i<=n;i++){
	 	dp[i][0]=min(abs(r[i]-l[i-1])+r[i]-l[i]+dp[i-1][0],abs(r[i]-r[i-1])+r[i]-l[i]+dp[i-1][1]);
		dp[i][1]=min(abs(l[i]-l[i-1])+r[i]-l[i]+dp[i-1][0],abs(l[i]-r[i-1])+r[i]-l[i]+dp[i-1][1]);

	}
	cout<<min(dp[n][0]+n-l[n],dp[n][1]+n-r[n])+n-1;//加上竖着走的
	return 0;
}