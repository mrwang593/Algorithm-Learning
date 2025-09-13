#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline void print(__int128 x){
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
int main(){
	int n,w;
	cin>>n>>w;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<__int128>dp(w+1,0);
	dp[0]=1;
	for(int i=1;i<=w;i++){
		for(int j=0;j<n;j++){
			if(i-a[j]>=0&&dp[i-a[j]]!=0) {
				dp[i]+=dp[i-a[j]];
				dp[i]%=mod;
			}
		}
	}
	print(dp[w]);
	return 0;
}